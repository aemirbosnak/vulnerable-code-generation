//MISTRAL-7B DATASET v1.0 Category: Electronic Voting System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_USERS 100
#define MAX_NAME_LENGTH 20
#define MAX_OPTIONS 5
#define CONFIG_FILE "config.txt"

typedef struct {
    char name[MAX_NAME_LENGTH];
    int vote;
} User;

typedef struct {
    char option[MAX_NAME_LENGTH];
    int votes;
} Option;

Option options[MAX_OPTIONS];
User users[MAX_USERS];
int num_users = 0;
int num_options = 0;

void load_config() {
    FILE *config_file = fopen(CONFIG_FILE, "r");

    if (config_file == NULL) {
        printf("Error: Unable to open configuration file.\n");
        exit(1);
    }

    char line[100];
    while (fgets(line, sizeof(line), config_file)) {
        char option_name[MAX_NAME_LENGTH];
        sscanf(line, "%s", option_name);

        if (num_options < MAX_OPTIONS) {
            strcpy(options[num_options].option, option_name);
            options[num_options].votes = 0;
            num_options++;
        }
    }

    fclose(config_file);
}

void register_user(char *name) {
    if (num_users < MAX_USERS) {
        strcpy(users[num_users].name, name);
        users[num_users].vote = 0;
        num_users++;
    } else {
        printf("Error: Maximum number of users reached.\n");
    }
}

int find_user_index(char *name) {
    for (int i = 0; i < num_users; i++) {
        if (strcmp(users[i].name, name) == 0) {
            return i;
        }
    }

    return -1;
}

void vote(char *name, int option_index) {
    int user_index = find_user_index(name);

    if (user_index != -1) {
        users[user_index].vote = option_index;
        options[option_index].votes++;
    } else {
        printf("Error: User not found.\n");
    }
}

void print_vote_count() {
    printf("\nCurrent vote count:\n");

    for (int i = 0; i < num_options; i++) {
        printf("%s: %d votes\n", options[i].option, options[i].votes);
    }
}

int main() {
    load_config();

    char name[MAX_NAME_LENGTH];
    int option_index;

    while (1) {
        printf("\nWelcome to the Electronic Voting System\n");
        printf("1. Register\n2. Vote\n3. View vote count\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option_index);

        switch (option_index) {
            case 1:
                printf("Enter your name: ");
                scanf("%s", name);
                register_user(name);
                break;
            case 2:
                printf("Enter your name: ");
                scanf("%s", name);
                printf("Enter option index: ");
                scanf("%d", &option_index);
                vote(name, option_index - 1);
                break;
            case 3:
                print_vote_count();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}