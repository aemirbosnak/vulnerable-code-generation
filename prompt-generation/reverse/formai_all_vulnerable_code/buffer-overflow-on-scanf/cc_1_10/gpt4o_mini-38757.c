//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

void get_system_info() {
    struct passwd *pw;
    struct group *gr;
    char hostname[256];
    char *user;
    time_t t;

    // Get the current user
    user = getlogin();
    printf("User: %s\n", user);

    // Get the hostname
    gethostname(hostname, sizeof(hostname));
    printf("Hostname: %s\n", hostname);

    // Get the user info
    pw = getpwuid(getuid());
    printf("User ID: %d\n", pw->pw_uid);
    printf("Home Directory: %s\n", pw->pw_dir);

    // Get the current group info
    gr = getgrgid(getgid());
    printf("Group ID: %d\n", gr->gr_gid);
    printf("Group Name: %s\n", gr->gr_name);

    // Print current time
    t = time(NULL);
    printf("Current time: %s", ctime(&t));

    // List files in current directory
    printf("Files in current directory:\n");
    system("ls -l");
}

void list_running_processes() {
    printf("\nRunning processes:\n");
    system("ps -aux");
}

void check_disk_usage() {
    printf("\nDisk usage:\n");
    system("df -h");
}

void check_memory_usage() {
    printf("\nMemory usage:\n");
    system("free -h");
}

void display_menu() {
    printf("System Administration Tool\n");
    printf("1. Get System Info\n");
    printf("2. List Running Processes\n");
    printf("3. Check Disk Usage\n");
    printf("4. Check Memory Usage\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

int main() {
    int option;

    do {
        display_menu();
        scanf("%d", &option);

        switch (option) {
            case 1:
                get_system_info();
                break;
            case 2:
                list_running_processes();
                break;
            case 3:
                check_disk_usage();
                break;
            case 4:
                check_memory_usage();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option, please try again.\n");
        }

        // For visual clarity, separate outputs
        printf("\n");
    } while (option != 5);

    return 0;
}