//FormAI DATASET v1.0 Category: Database simulation ; Style: paranoid
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_RECORDS 100

struct user {
    char username[30];
    char password[30];
};

struct record {
    char website[50];
    char username[30];
    char password[30];
};

void add_record(struct user users[], int num_users, struct record records[], int num_records) {
    char website[50];
    char username[30];
    char password[30];

    printf("\nEnter website: ");
    scanf("%s", website);

    printf("\nEnter username: ");
    scanf("%s", username);

    printf("\nEnter password: ");
    scanf("%s", password);

    // verify user credentials
    char entered_username[30];
    char entered_password[30];
    printf("\nEnter username to authenticate: ");
    scanf("%s", entered_username);

    printf("\nEnter password to authenticate: ");
    scanf("%s", entered_password);

    int authenticated = 0;
    for(int i = 0; i < num_users; i++) {
        if(strcmp(users[i].username, entered_username) == 0 && strcmp(users[i].password, entered_password) == 0) {
            authenticated = 1;
            break;
        }
    }

    if(authenticated) {
        struct record new_record;
        strcpy(new_record.website, website);
        strcpy(new_record.username, username);
        strcpy(new_record.password, password);

        records[num_records] = new_record;
        num_records++;

        printf("\nRecord added successfully!");
    }
    else {
        printf("\nInvalid credentials. Record could not be added.");
    }
}

void delete_record(struct user users[], int num_users, struct record records[], int num_records) {
    char website[50];

    printf("\nEnter website to delete: ");
    scanf("%s", website);

    // verify user credentials
    char entered_username[30];
    char entered_password[30];
    printf("\nEnter username to authenticate: ");
    scanf("%s", entered_username);

    printf("\nEnter password to authenticate: ");
    scanf("%s", entered_password);

    int authenticated = 0;
    for(int i = 0; i < num_users; i++) {
        if(strcmp(users[i].username, entered_username) == 0 && strcmp(users[i].password, entered_password) == 0) {
            authenticated = 1;
            break;
        }
    }

    if(authenticated) {
        int record_found = 0;
        for(int i = 0; i < num_records; i++) {
            if(strcmp(records[i].website, website) == 0) {
                for(int j = i; j < num_records-1; j++) {
                    records[j] = records[j+1];
                }
                num_records--;
                record_found = 1;
                printf("\nRecord deleted successfully!");
                break;
            }
        }
        if(!record_found) {
            printf("\nRecord not found!");
        }
    }
    else {
        printf("\nInvalid credentials. Record could not be deleted.");
    }
}

void list_records(struct user users[], int num_users, struct record records[], int num_records) {
    // verify user credentials
    char entered_username[30];
    char entered_password[30];
    printf("\nEnter username to authenticate: ");
    scanf("%s", entered_username);

    printf("\nEnter password to authenticate: ");
    scanf("%s", entered_password);

    int authenticated = 0;
    for(int i = 0; i < num_users; i++) {
        if(strcmp(users[i].username, entered_username) == 0 && strcmp(users[i].password, entered_password) == 0) {
            authenticated = 1;
            break;
        }
    }

    if(authenticated) {
        printf("\nWebsite\t\tUsername\tPassword");
        for(int i = 0; i < num_records; i++) {
            printf("\n%s\t\t%s\t\t%s", records[i].website, records[i].username, records[i].password);
        }
    }
    else {
        printf("\nInvalid credentials. Records could not be listed.");
    }
}

void change_password(struct user users[], int num_users) {
    char entered_username[30];
    char entered_password[30];
    printf("\nEnter username to authenticate: ");
    scanf("%s", entered_username);

    printf("\nEnter password to authenticate: ");
    scanf("%s", entered_password);

    int authenticated = 0;
    int user_index = -1;
    for(int i = 0; i < num_users; i++) {
        if(strcmp(users[i].username, entered_username) == 0 && strcmp(users[i].password, entered_password) == 0) {
            authenticated = 1;
            user_index = i;
            break;
        }
    }

    if(authenticated) {
        // change password
        char new_password[30];
        printf("\nEnter new password: ");
        scanf("%s", new_password);

        // paranoid check
        if(strlen(new_password) < 8) {
            printf("\nPassword must be at least 8 characters long. Password cannot be changed.");
            return;
        }

        int has_uppercase = 0;
        int has_lowercase = 0;
        int has_digit = 0;
        int has_special = 0;

        for(int i = 0; i < strlen(new_password); i++) {
            if(new_password[i] >= 'A' && new_password[i] <= 'Z') {
                has_uppercase = 1;
            }
            else if(new_password[i] >= 'a' && new_password[i] <= 'z') {
                has_lowercase = 1;
            }
            else if(new_password[i] >= '0' && new_password[i] <= '9') {
                has_digit = 1;
            }
            else {
                has_special = 1;
            }
        }

        if(!has_uppercase || !has_lowercase || !has_digit || !has_special) {
            printf("\nPassword must contain at least one uppercase character, one lowercase character, one digit and one special character. Password cannot be changed.");
            return;
        }

        strcpy(users[user_index].password, new_password);

        printf("\nPassword changed successfully!");
    }
    else {
        printf("\nInvalid credentials. Password could not be changed.");
    }
}

int main() {
    struct user users[5] = {
        {"user1", "password1"},
        {"user2", "password2"},
        {"user3", "password3"},
        {"user4", "password4"},
        {"user5", "password5"}
    };
    int num_users = 5;

    struct record records[MAX_RECORDS];
    int num_records = 0;

    while(1) {
        printf("\n1. Add record\n");
        printf("2. Delete record\n");
        printf("3. List records\n");
        printf("4. Change password\n");
        printf("5. Exit\n");

        int option;
        printf("\nEnter option: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                add_record(users, num_users, records, num_records);
                break;
            case 2:
                delete_record(users, num_users, records, num_records);
                break;
            case 3:
                list_records(users, num_users, records, num_records);
                break;
            case 4:
                change_password(users, num_users);
                break;
            case 5:
                printf("\nExiting program.\n");
                exit(0);
            default:
                printf("\nInvalid option. Please enter a valid option.\n");
                break;
        }
    }
    return 0;
}