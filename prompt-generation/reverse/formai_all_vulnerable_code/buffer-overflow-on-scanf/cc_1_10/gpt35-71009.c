//FormAI DATASET v1.0 Category: Password management ; Style: modular
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Function to add a new password to the list
void add_password(char* password_list[], int* num_passwords) {
    char password[50];
    printf("Enter the new password: ");
    scanf("%s", password);
    // Allocate a new memory for the password
    password_list[*num_passwords] = (char*)malloc(sizeof(char) * strlen(password));
    strcpy(password_list[*num_passwords], password);
    (*num_passwords)++;
    printf("New password added successfully!\n");
}

// Function to view all the saved passwords
void view_passwords(char* password_list[], int num_passwords) {
    if(num_passwords == 0) {
        printf("No passwords found!\n");
        return;
    }
    printf("List of saved passwords:\n");
    for(int i=0; i<num_passwords; i++) {
        printf("%d. %s\n", i+1, password_list[i]);
    }
}

// Function to delete a password from the list
void delete_password(char* password_list[], int* num_passwords) {
    if(*num_passwords == 0) {
        printf("No passwords found!\n");
        return;
    }
    int index;
    printf("Enter the index of the password you want to delete: ");
    scanf("%d", &index);
    // Check for valid index input
    if(index <= 0 || index > *num_passwords) {
        printf("Invalid index!\n");
        return;
    }
    // Free the memory allocated for the password and shift the array elements to left
    free(password_list[index-1]);
    for(int i=index-1; i<*num_passwords-1; i++) {
        password_list[i] = password_list[i+1];
    }
    (*num_passwords)--;
    printf("Password deleted successfully!\n");
}

// Main function
int main() {
    int num_passwords = 0;
    char* password_list[50];
    int choice;
    do {
        printf("\n-----PASSWORD MANAGEMENT SYSTEM-----\n");
        printf("1. Add a new password\n2. View saved passwords\n3. Delete a password\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        // Switch case for various operations
        switch(choice) {
            case 1:
                add_password(password_list, &num_passwords);
                break;
            case 2:
                view_passwords(password_list, num_passwords);
                break;
            case 3:
                delete_password(password_list, &num_passwords);
                break;
            case 4:
                printf("Exiting Password Management System...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while(choice != 4);
    return 0;
}