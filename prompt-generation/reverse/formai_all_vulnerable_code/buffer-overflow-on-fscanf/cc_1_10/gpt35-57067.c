//FormAI DATASET v1.0 Category: Mailing list manager ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 1000
#define MAX_EMAIL_LEN 50

// function prototypes
void print_menu();
void print_list(char *emails[], int n);
void add_email(char *emails[], int *n);
void remove_email(char *emails[], int *n);
void find_duplicates(char *emails[], int n);
void sort_list(char *emails[], int n);
void save_list(char *emails[], int n);
void load_list(char *emails[], int *n);

int main()
{
    char *emails[MAX_EMAILS];
    int n = 0;
    int choice;

    do {
        print_menu();
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_email(emails, &n);
                break;
            case 2:
                remove_email(emails, &n);
                break;
            case 3:
                find_duplicates(emails, n);
                break;
            case 4:
                sort_list(emails, n);
                break;
            case 5:
                save_list(emails, n);
                break;
            case 6:
                load_list(emails, &n);
                break;
            case 7:
                // exit program
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while(choice != 7);

    printf("Goodbye!\n");
    return 0;
}

void print_menu()
{
    printf("1. Add email address\n");
    printf("2. Remove email address\n");
    printf("3. Find duplicates\n");
    printf("4. Sort list\n");
    printf("5. Save list to file\n");
    printf("6. Load list from file\n");
    printf("7. Quit\n");
    printf("Enter your choice: ");
}

void print_list(char *emails[], int n)
{
    printf("Current list of email addresses:\n");
    for(int i = 0; i < n; i++) {
        printf("%s\n", emails[i]);
    }
}

void add_email(char *emails[], int *n)
{
    if(*n == MAX_EMAILS) {
        printf("List is full, cannot add more emails.\n");
        return;
    }

    char email[MAX_EMAIL_LEN];
    printf("Enter email address: ");
    scanf("%s", email);

    // check for duplicates
    for(int i = 0; i < *n; i++) {
        if(strcmp(emails[i], email) == 0) {
            printf("Email address already exists in list.\n");
            return;
        }
    }

    // add email to list
    emails[*n] = (char *) malloc(strlen(email) + 1);
    strcpy(emails[*n], email);

    (*n)++; // increment count of emails
    printf("Email address added to list.\n");
}

void remove_email(char *emails[], int *n)
{
    if(*n == 0) {
        printf("List is empty, cannot remove email.\n");
        return;
    }

    char email[MAX_EMAIL_LEN];
    printf("Enter email address to remove: ");
    scanf("%s", email);

    int index = -1;
    // find index of email to remove
    for(int i = 0; i < *n; i++) {
        if(strcmp(emails[i], email) == 0) {
            index = i;
            break;
        }
    }

    if(index == -1) {
        printf("Email address not found in list.\n");
        return;
    }

    // free memory for email and shift remaining emails
    free(emails[index]);
    for(int i = index; i < *n - 1; i++) {
        emails[i] = emails[i+1];
    }
    (*n)--; // decrement count of emails
    printf("Email address removed from list.\n");
}

void find_duplicates(char *emails[], int n)
{
    if(n == 0) {
        printf("List is empty, cannot find duplicates.\n");
        return;
    }

    int count = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            if(strcmp(emails[i], emails[j]) == 0) {
                printf("%s is a duplicate of %s.\n", emails[j], emails[i]);
                count++;
            }
        }
    }

    if(count == 0) {
        printf("No duplicates found in list.\n");
    }
}

void sort_list(char *emails[], int n)
{
    if(n == 0) {
        printf("List is empty, cannot sort.\n");
        return;
    }

    // use bubble sort algorithm to sort emails
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(strcmp(emails[j], emails[j+1]) > 0) {
                char *temp = emails[j];
                emails[j] = emails[j+1];
                emails[j+1] = temp;
            }
        }
    }
    printf("List sorted alphabetically.\n");
}

void save_list(char *emails[], int n)
{
    if(n == 0) {
        printf("List is empty, cannot save.\n");
        return;
    }

    char filename[50];
    printf("Enter filename to save to: ");
    scanf("%s", filename);

    FILE *fp = fopen(filename, "w");
    if(fp == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    for(int i = 0; i < n; i++) {
        fprintf(fp, "%s\n", emails[i]);
    }

    fclose(fp);
    printf("List saved to file %s.\n", filename);
}

void load_list(char *emails[], int *n)
{
    char filename[50];
    printf("Enter filename to load from: ");
    scanf("%s", filename);

    FILE *fp = fopen(filename, "r");
    if(fp == NULL) {
        printf("Error opening file for reading.\n");
        return;
    }

    char email[MAX_EMAIL_LEN];
    int count = 0;
    while(fscanf(fp, "%s", email) != EOF && count < MAX_EMAILS) {
        emails[count] = (char *) malloc(strlen(email) + 1);
        strcpy(emails[count], email);
        count++;
    }

    fclose(fp);
    *n = count;
    printf("%d emails loaded from file %s.\n", count, filename);
}