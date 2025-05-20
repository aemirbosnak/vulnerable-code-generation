//GPT-4o-mini DATASET v1.0 Category: Mailing list manager ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100
#define MAX_LENGTH 255

void displayEmails(char emails[MAX_EMAILS][MAX_LENGTH], int count) {
    printf("\nCurrent Mailing List:\n");
    for (int i = 0; i < count; i++) {
        printf("%d: %s\n", i + 1, emails[i]);
    }
}

void addEmail(char emails[MAX_EMAILS][MAX_LENGTH], int *count) {
    if (*count >= MAX_EMAILS) {
        printf("Mailing list is full! Cannot add more emails.\n");
        return;
    }
    
    char email[MAX_LENGTH];
    printf("Enter the email address to add: ");
    scanf("%s", email);
    
    for (int i = 0; i < *count; i++) {
        if (strcmp(emails[i], email) == 0) {
            printf("Email already exists in the mailing list!\n");
            return;
        }
    }
    
    strcpy(emails[*count], email);
    (*count)++;
    printf("Email added successfully!\n");
}

void removeEmail(char emails[MAX_EMAILS][MAX_LENGTH], int *count) {
    if (*count == 0) {
        printf("Mailing list is empty! Cannot remove any emails.\n");
        return;
    }
    
    int index;
    displayEmails(emails, *count);
    printf("Enter the index of the email to remove: ");
    scanf("%d", &index);
    
    if (index < 1 || index > *count) {
        printf("Invalid index! Please try again.\n");
        return;
    }
    
    for (int i = index - 1; i < *count - 1; i++) {
        strcpy(emails[i], emails[i + 1]);
    }

    (*count)--;
    printf("Email removed successfully!\n");
}

void saveEmailsToFile(char emails[MAX_EMAILS][MAX_LENGTH], int count) {
    FILE *file = fopen("mailing_list.txt", "w");
    if (!file) {
        perror("Failed to open file");
        return;
    }
    
    for (int i = 0; i < count; i++) {
        fprintf(file, "%s\n", emails[i]);
    }
    
    fclose(file);
    printf("Mailing list saved to mailing_list.txt\n");
}

void loadEmailsFromFile(char emails[MAX_EMAILS][MAX_LENGTH], int *count) {
    FILE *file = fopen("mailing_list.txt", "r");
    if (!file) {
        printf("No saved mailing list found. Starting fresh!\n");
        return;
    }
    
    while (fgets(emails[*count], MAX_LENGTH, file) && *count < MAX_EMAILS) {
        emails[*count][strcspn(emails[*count], "\n")] = 0; // Remove trailing newline
        (*count)++;
    }
    
    fclose(file);
    printf("Mailing list loaded from mailing_list.txt\n");
}

int main() {
    char emails[MAX_EMAILS][MAX_LENGTH];
    int count = 0, choice;

    loadEmailsFromFile(emails, &count);

    while (1) {
        printf("\nMailing List Manager\n");
        printf("1. Display Emails\n");
        printf("2. Add Email\n");
        printf("3. Remove Email\n");
        printf("4. Save Emails to File\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayEmails(emails, count);
                break;
            case 2:
                addEmail(emails, &count);
                break;
            case 3:
                removeEmail(emails, &count);
                break;
            case 4:
                saveEmailsToFile(emails, count);
                break;
            case 5:
                saveEmailsToFile(emails, count);
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}