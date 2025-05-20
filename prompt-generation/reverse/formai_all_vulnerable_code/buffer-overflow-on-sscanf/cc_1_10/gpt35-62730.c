//FormAI DATASET v1.0 Category: System administration ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>

#define MAX_LEN 512

int main(int argc, char *argv[]) {
    if(argc != 3) {
        printf("Invalid number of arguments\n");
        exit(1);
    }
    //Get the current user ID
    uid_t uid = getuid();

    //Check if the user has root privileges
    if(uid != 0) {
        printf("This program requires root privileges\n");
        exit(1);
    }

    //Check if the first argument is a valid path
    struct stat pathstat;
    if(stat(argv[1], &pathstat) == -1) {
        printf("Invalid path provided\n");
        exit(1);
    }
    //Check if the second argument is a valid user id
    uid_t opuid;
    if(sscanf(argv[2], "%u", &opuid) != 1) {
        printf("Invalid user id provided\n");
        exit(1);
    }

    // Create a new user account with provided user id and home directory
    char cmd1[MAX_LEN];
    snprintf(cmd1, MAX_LEN, "useradd --home %s -u %d newuser", argv[1], opuid);
    system(cmd1);

    //Create a new group with the name of the new user
    char cmd2[MAX_LEN];
    snprintf(cmd2, MAX_LEN, "groupadd newuser");
    system(cmd2);

    //Add the new user to the new group
    char cmd3[MAX_LEN];
    snprintf(cmd3, MAX_LEN, "usermod -aG newuser newuser");
    system(cmd3);

    //Change ownership of all files in the provided path to the new user and group
    char cmd4[MAX_LEN];
    snprintf(cmd4, MAX_LEN, "chown -R newuser:newuser %s", argv[1]);
    system(cmd4);

    //Give the new user access to all files in the provided path
    char cmd5[MAX_LEN];
    snprintf(cmd5, MAX_LEN, "chmod -R u+rwx %s", argv[1]);
    system(cmd5);

    printf("New user created successfully!\n");
    return 0;
}