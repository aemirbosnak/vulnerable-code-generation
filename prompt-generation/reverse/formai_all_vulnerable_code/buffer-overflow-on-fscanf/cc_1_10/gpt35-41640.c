//FormAI DATASET v1.0 Category: Password management ; Style: brave
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct password {
    char name[50];
    char password[50];
};

void savePasswordFile(struct password pass[], int n) {
    FILE *fptr = fopen("passwords.txt", "w");
    if (fptr == NULL) {
        printf("Error opening file!");
        exit(1);
    }
    for (int i=0; i<n; i++) {
        fprintf(fptr, "%s %s\n", pass[i].name, pass[i].password);
    }
    fclose(fptr);
}

void getPasswordFile(struct password pass[], int *n) {
    FILE *fptr = fopen("passwords.txt", "r");
    if (fptr == NULL) {
        printf("Error opening file!");
        exit(1);
    }
    *n = 0;
    while(fscanf(fptr, "%s %s\n", pass[*n].name, pass[*n].password) != EOF) {
        *n = *n + 1;
    }
    fclose(fptr);
}

int main() {
    struct password pass[100];
    int n = 0;

    getPasswordFile(pass, &n);

    int choice = -1;
    while (1) {
        printf("\n\nP A S S W O R D    M A N A G E M E N T   S Y S T E M\n");
        printf("----------------------------------------------------\n\n");
        printf("1. Add passwords\n");
        printf("2. View passwords\n");
        printf("3. Change password\n");
        printf("4. Delete password\n");
        printf("5. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("\nEnter name: ");
            scanf("%s", pass[n].name);
            printf("\nEnter password: ");
            scanf("%s", pass[n].password);
            printf("\nPassword saved successfully!");
            savePasswordFile(pass, n+1);
            n++;
        }
        else if (choice == 2) {
            printf("\n------------------------------------");
            printf("\n|   Name\t\t|   Password\t|");
            printf("\n------------------------------------");
            for (int i=0; i<n; i++) {
                printf("\n|   %s\t\t|   %s\t\t|", pass[i].name, pass[i].password);
            }
            printf("\n------------------------------------");
        }
        else if (choice == 3) {
            printf("\nEnter the name of password to change: ");
            char passwordName[50];
            scanf("%s", passwordName);
            for (int i=0; i<n; i++) {
                if (strcmp(pass[i].name, passwordName) == 0) {
                    printf("\nEnter new password: ");
                    scanf("%s", pass[i].password);
                    printf("\nPassword changed successfully!");
                    savePasswordFile(pass, n);
                    break;
                }
                if (i == n-1) {
                    printf("\nPassword not found!");
                }
            }
        }
        else if (choice == 4) {
            printf("\nEnter the name of password to delete: ");
            char passwordName[50];
            scanf("%s", passwordName);
            for (int i=0; i<n; i++) {
                if (strcmp(pass[i].name, passwordName) == 0) {
                    for (int j=i; j<n-1; j++) {
                        pass[j] = pass[j+1];
                    }
                    n--;
                    printf("\nPassword deleted successfully!");
                    savePasswordFile(pass, n);
                    break;
                }
                if (i == n-1) {
                    printf("\nPassword not found!");
                }
            }
        }
        else if (choice == 5) {
            printf("\nExiting...");
            break;
        }
        else {
            printf("\nInvalid choice!");
        }
    }
    return 0;
}