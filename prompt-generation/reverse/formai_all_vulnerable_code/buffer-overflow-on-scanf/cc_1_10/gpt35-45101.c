//FormAI DATASET v1.0 Category: Password management ; Style: statistical
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

// Define struct to store password information
struct password_info {
    char account_name[50];
    char user_name[50];
    char password[50];
};

// Define function to print list of passwords
void print_passwords(struct password_info* passwords, int num_passwords) {
    printf("\n=====PASSWORD LIST=====\n");
    for (int i = 0; i < num_passwords; i++) {
        printf("Account Name: %s\n", passwords[i].account_name);
        printf("User Name: %s\n", passwords[i].user_name);
        printf("Password: %s\n", passwords[i].password);
        printf("\n");
    }
}

// Define function to add new password
void add_password(struct password_info* passwords, int* num_passwords) {
    printf("\n=====ADD NEW PASSWORD=====\n");
    printf("Enter Account Name: ");
    scanf("%s", passwords[*num_passwords].account_name);
    printf("Enter User Name: ");
    scanf("%s", passwords[*num_passwords].user_name);
    printf("Enter Password: ");
    scanf("%s", passwords[*num_passwords].password);
    (*num_passwords)++;
    printf("Password added successfully!\n");
}

// Define function to generate a random password
void generate_password(char* password) {
    char seed_characters[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+-={}[]|\\:;\"'<>,.?/";
    int password_length = 10;
    int num_seed_characters = strlen(seed_characters);
    for (int i = 0; i < password_length; i++) {
        int random_index = rand() % num_seed_characters;
        password[i] = seed_characters[random_index];
    }
    password[password_length] = '\0';
}

// Define function to change master password
void change_master_password(char* master_password) {
    printf("\n=====CHANGE MASTER PASSWORD=====\n");
    printf("Enter current master password: ");
    char current_password[50];
    scanf("%s", current_password);
    if (strcmp(current_password, master_password) != 0) {
        printf("Incorrect password!\n");
        return;
    }
    printf("Enter new master password: ");
    scanf("%s", master_password);
    printf("Master password changed successfully!\n");
}

// Main function to run password manager program
int main() {
    // Prompt user to enter master password
    printf("=====WELCOME TO PASSWORD MANAGER=====\n");
    char master_password[50];
    printf("Please enter a master password: ");
    scanf("%s", master_password);

    // Define an array to store passwords and a counter for number of passwords
    struct password_info passwords[50];
    int num_passwords = 0;

    // Main loop to allow user to interact with password manager
    char command = ' ';
    while (command != 'q') {
        printf("\n=====MAIN MENU=====\n");
        printf("1. Print Passwords\n");
        printf("2. Add a Password\n");
        printf("3. Generate a Password\n");
        printf("4. Change Master Password\n");
        printf("q. Quit\n");
        printf("Enter command: ");
        scanf(" %c", &command);
        switch(command) {
            case '1':
                print_passwords(passwords, num_passwords);
                break;
            case '2':
                add_password(passwords, &num_passwords);
                break;
            case '3': {
                char new_password[50];
                generate_password(new_password);
                printf("Generated Password: %s\n", new_password);
                break; }
            case '4':
                change_master_password(master_password);
                break;
            case 'q':
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid command!\n");
                break;
        }
    }
    return 0;
}