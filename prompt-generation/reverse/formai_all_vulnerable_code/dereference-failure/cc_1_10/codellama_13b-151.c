//Code Llama-13B DATASET v1.0 Category: System administration ; Style: surprised
// Program: Unique C System Administration Example Program
// Description: This program performs a variety of system administration tasks, such as creating and deleting users,
//             modifying user passwords, and managing file permissions.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>

// Function to create a new user
void create_user(char *username, char *password) {
    // Create a new user account
    struct passwd *user = getpwnam(username);
    if (user == NULL) {
        user = (struct passwd *) malloc(sizeof(struct passwd));
        user->pw_name = strdup(username);
        user->pw_passwd = strdup(password);
        user->pw_uid = getuid();
        user->pw_gid = getgid();
        user->pw_gecos = strdup("");
        user->pw_dir = strdup("/home/");
        user->pw_shell = strdup("/bin/bash");
        setpwent();
        putpwent(user, stdout);
        endpwent();
    } else {
        printf("User '%s' already exists.\n", username);
    }
}

// Function to delete a user
void delete_user(char *username) {
    // Delete the user account
    struct passwd *user = getpwnam(username);
    if (user == NULL) {
        printf("User '%s' does not exist.\n", username);
    } else {
        endpwent();
        setpwent();
        putpwent(user, stdout);
        endpwent();
    }
}

// Function to modify the password for a user
void modify_password(char *username, char *password) {
    // Modify the password for the user account
    struct passwd *user = getpwnam(username);
    if (user == NULL) {
        printf("User '%s' does not exist.\n", username);
    } else {
        user->pw_passwd = strdup(password);
        setpwent();
        putpwent(user, stdout);
        endpwent();
    }
}

// Function to manage file permissions
void manage_permissions(char *filename, char *permission) {
    // Modify the file permissions
    struct stat sb;
    if (stat(filename, &sb) == -1) {
        printf("File '%s' does not exist.\n", filename);
    } else {
        int mode = sb.st_mode;
        if (permission == "r") {
            mode |= S_IRUSR;
        } else if (permission == "w") {
            mode |= S_IWUSR;
        } else if (permission == "x") {
            mode |= S_IXUSR;
        } else {
            printf("Invalid permission '%s'.\n", permission);
            return;
        }
        if (chmod(filename, mode) == -1) {
            printf("Error modifying permissions for file '%s'.\n", filename);
        } else {
            printf("Permissions for file '%s' modified.\n", filename);
        }
    }
}

// Function to manage file ownership
void manage_ownership(char *filename, char *username, char *group) {
    // Modify the file ownership
    struct stat sb;
    if (stat(filename, &sb) == -1) {
        printf("File '%s' does not exist.\n", filename);
    } else {
        uid_t uid = getuid();
        gid_t gid = getgid();
        if (username != NULL) {
            struct passwd *user = getpwnam(username);
            if (user == NULL) {
                printf("User '%s' does not exist.\n", username);
                return;
            } else {
                uid = user->pw_uid;
            }
        }
        if (group != NULL) {
            struct group *grp = getgrnam(group);
            if (grp == NULL) {
                printf("Group '%s' does not exist.\n", group);
                return;
            } else {
                gid = grp->gr_gid;
            }
        }
        if (chown(filename, uid, gid) == -1) {
            printf("Error modifying ownership for file '%s'.\n", filename);
        } else {
            printf("Ownership for file '%s' modified.\n", filename);
        }
    }
}

int main(int argc, char *argv[]) {
    // Check the command line arguments
    if (argc < 3) {
        printf("Usage: %s <command> <args>\n", argv[0]);
        printf("Commands:\n");
        printf("  create_user <username> <password>\n");
        printf("  delete_user <username>\n");
        printf("  modify_password <username> <password>\n");
        printf("  manage_permissions <filename> <permission>\n");
        printf("  manage_ownership <filename> <username> <group>\n");
        return 1;
    }

    // Execute the requested command
    if (strcmp(argv[1], "create_user") == 0) {
        create_user(argv[2], argv[3]);
    } else if (strcmp(argv[1], "delete_user") == 0) {
        delete_user(argv[2]);
    } else if (strcmp(argv[1], "modify_password") == 0) {
        modify_password(argv[2], argv[3]);
    } else if (strcmp(argv[1], "manage_permissions") == 0) {
        manage_permissions(argv[2], argv[3]);
    } else if (strcmp(argv[1], "manage_ownership") == 0) {
        manage_ownership(argv[2], argv[3], argv[4]);
    } else {
        printf("Invalid command '%s'.\n", argv[1]);
        return 1;
    }

    return 0;
}