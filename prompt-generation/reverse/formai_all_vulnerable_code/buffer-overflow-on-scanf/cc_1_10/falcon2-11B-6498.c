//Falcon2-11B DATASET v1.0 Category: Electronic Voting System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void print_menu() {
    printf("1. Register a new voter\n");
    printf("2. View registered voters\n");
    printf("3. Vote\n");
    printf("4. Exit\n");
}

void register_voter(char* name, char* email, char* password) {
    FILE* f = fopen("voters.txt", "a");
    fprintf(f, "%s %s %s\n", name, email, password);
    fclose(f);
    printf("Voter registered successfully.\n");
}

void view_voters() {
    FILE* f = fopen("voters.txt", "r");
    char name[100], email[100], password[100];
    while (fscanf(f, "%s %s %s", name, email, password) == 3) {
        printf("Name: %s\n", name);
        printf("Email: %s\n", email);
        printf("Password: %s\n", password);
        printf("\n");
    }
    fclose(f);
}

void vote() {
    FILE* f = fopen("voters.txt", "r");
    char name[100], email[100], password[100];
    while (fscanf(f, "%s %s %s", name, email, password) == 3) {
        printf("Name: %s\n", name);
        printf("Email: %s\n", email);
        printf("Password: %s\n", password);
        printf("\n");
    }
    fclose(f);
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);
    if (choice == 1) {
        register_voter("John Doe", "john@example.com", "password123");
        printf("Voter registered successfully.\n");
    } else if (choice == 2) {
        view_voters();
    } else if (choice == 3) {
        char candidate[100];
        printf("Enter the candidate's name: ");
        fgets(candidate, sizeof(candidate), stdin);
        printf("Voting for %s...\n", candidate);
    } else {
        printf("Invalid choice. Exiting...\n");
        exit(1);
    }
}

int main() {
    srand(time(NULL));
    char choice;
    int i = 0;
    while (1) {
        print_menu();
        printf("Enter your choice: ");
        scanf(" %c", &choice);
        switch (choice) {
            case '1':
                register_voter("John Doe", "john@example.com", "password123");
                break;
            case '2':
                view_voters();
                break;
            case '3':
                vote();
                break;
            case '4':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
        i++;
        if (i % 5 == 0) {
            printf("Sleeping for 5 seconds...\n");
            sleep(5);
        }
    }
    return 0;
}