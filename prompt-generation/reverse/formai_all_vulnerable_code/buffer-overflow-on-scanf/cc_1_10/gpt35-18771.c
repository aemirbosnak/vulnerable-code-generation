//FormAI DATASET v1.0 Category: Password management ; Style: single-threaded
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_NAME_LEN 20
#define MAX_PASS_LEN 20

struct account {
    char name[MAX_NAME_LEN];
    char password[MAX_PASS_LEN];
    struct account *next;   
};

struct account* head = NULL;
struct account* current = NULL;

void printPasswords() {
    struct account* ptr = head;
    while(ptr != NULL) {
        printf("%s %s\n", ptr->name, ptr->password);
        ptr = ptr->next;
    }
}

void insertPassword() {
    char inputName[MAX_NAME_LEN], inputPassword[MAX_PASS_LEN];
    struct account* newAcc = (struct account*)malloc(sizeof(struct account));
    printf("Enter name: ");
    scanf("%s", inputName);
    printf("Enter password: ");
    scanf("%s", inputPassword);
    
    strncpy(newAcc->name, inputName, MAX_NAME_LEN);
    strncpy(newAcc->password, inputPassword, MAX_PASS_LEN);
    newAcc->next = NULL;
    
    if(head == NULL) {
        head = newAcc;
        current = newAcc;
    } else {
        current->next = newAcc;
        current = newAcc;
    }
    printf("Password successfully added!\n");
}

void deletePassword() {
    char inputName[MAX_NAME_LEN];
    printf("Enter the name of the password to delete: ");
    scanf("%s", inputName);
    
    struct account* prev = NULL;
    struct account* ptr = head;
    
    while(ptr != NULL) {
        if(strcmp(ptr->name, inputName) == 0) {
            printf("Password for account %s deleted!\n", inputName); 
            if(prev == NULL) {
                head = ptr->next;
            } else {
                prev->next = ptr->next;
            }
            free(ptr);
            return; 
        }
        prev = ptr;
        ptr = ptr->next;
    }
    printf("Password for account %s not found!\n", inputName);
}

int main() {
    int choice;
    
    while(1) {
        printf("\n1. Print Passwords\n2. Insert Password\n3. Delete Password\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                if(head == NULL) {
                    printf("No passwords added yet!\n");
                } else {
                    printPasswords();
                }
            break;
            case 2:
                insertPassword();
            break;
            case 3:
                if(head == NULL) {
                    printf("No passwords added yet!\n");
                } else {
                    deletePassword();
                }
            break;
            case 4:
                exit(0);
            break;
            default:
                printf("Invalid choice!\n");
            break;
        }
    }
    return 0;
}