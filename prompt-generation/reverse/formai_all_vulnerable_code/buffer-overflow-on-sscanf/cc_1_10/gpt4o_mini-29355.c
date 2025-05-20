//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <errno.h>

#define MAX_PATH_LENGTH 1024
#define MAX_CMD_LENGTH 256

void check_file_permissions(const char *filepath) {
    struct stat fileStat;

    if (stat(filepath, &fileStat) < 0) {
        perror("stat error");
        return;
    }

    printf("File: %s\n", filepath);
    printf("Owner: %d\n", fileStat.st_uid);
    printf("Group: %d\n", fileStat.st_gid);
    printf("Permissions: ");
    printf((fileStat.st_mode & S_IRUSR) ? "r" : "-");
    printf((fileStat.st_mode & S_IWUSR) ? "w" : "-");
    printf((fileStat.st_mode & S_IXUSR) ? "x" : "-");
    printf((fileStat.st_mode & S_IRGRP) ? "r" : "-");
    printf((fileStat.st_mode & S_IWGRP) ? "w" : "-");
    printf((fileStat.st_mode & S_IXGRP) ? "x" : "-");
    printf((fileStat.st_mode & S_IROTH) ? "r" : "-");
    printf((fileStat.st_mode & S_IWOTH) ? "w" : "-");
    printf((fileStat.st_mode & S_IXOTH) ? "x" : "-");
    printf("\n\n");
}

void execute_command(const char *cmd) {
    int ret = system(cmd);
    if (ret == -1) {
        perror("system error");
    }
}

void display_user_info() {
    struct passwd *pw = getpwuid(getuid());
    if (pw) {
        printf("Username: %s\n", pw->pw_name);
        printf("Home Directory: %s\n", pw->pw_dir);
        printf("Shell: %s\n", pw->pw_shell);
    } else {
        perror("getpwuid error");
    }
}

void show_running_processes() {
    printf("Running processes:\n");
    execute_command("ps -aux | less");
}

void change_directory(const char *path) {
    if (chdir(path) != 0) {
        perror("chdir error");
    } else {
        printf("Changed directory to: %s\n", path);
    }
}

void secure_file_copy(const char *src, const char *dest) {
    FILE *source, *destination;
    char buffer[BUFSIZ];
    size_t bytes;

    source = fopen(src, "rb");
    if (source == NULL) {
        perror("Source file opening error");
        return;
    }

    destination = fopen(dest, "wb");
    if (destination == NULL) {
        perror("Destination file opening error");
        fclose(source);
        return;
    }

    while ((bytes = fread(buffer, 1, sizeof(buffer), source)) > 0) {
        fwrite(buffer, 1, bytes, destination);
    }

    fclose(source);
    fclose(destination);
    printf("File copied from %s to %s successfully!\n", src, dest);
}

void print_help() {
    printf("System Administration Utility\n");
    printf("Available Commands:\n");
    printf("1. check <filepath> - Check the permissions of a file\n");
    printf("2. user_info - Display user info\n");
    printf("3. processes - Show running processes\n");
    printf("4. cd <path> - Change directory\n");
    printf("5. copy <source> <destination> - Securely copy a file\n");
    printf("6. exit - Exit the utility\n");
}

int main() {
    char input[MAX_CMD_LENGTH];
    char cmd[MAX_CMD_LENGTH];

    print_help();
    while(1) {
        printf("> ");
        if (fgets(input, sizeof(input), stdin) == NULL) {
            break; // Handle EOF or read error
        }
        
        // Remove newline character from input
        input[strcspn(input, "\n")] = 0;

        if (sscanf(input, "check %s", cmd) == 1) {
            check_file_permissions(cmd);
        } else if (strcmp(input, "user_info") == 0) {
            display_user_info();
        } else if (strcmp(input, "processes") == 0) {
            show_running_processes();
        } else if (sscanf(input, "cd %s", cmd) == 1) {
            change_directory(cmd);
        } else if (sscanf(input, "copy %s %s", cmd, cmd + MAX_CMD_LENGTH/2) == 2) {
            secure_file_copy(cmd, cmd + MAX_CMD_LENGTH/2);
        } else if (strcmp(input, "exit") == 0) {
            break;
        } else {
            printf("Unknown command. Type 'help' to see available commands.\n");
        }
    }
    
    return 0;
}