//FormAI DATASET v1.0 Category: Mailing list manager ; Style: mind-bending
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

typedef struct node{
    char email[MAX];
    struct node* next;
}node;

void addEmail(node** start, char email[]){
    node* newNode = (node*)malloc(sizeof(node));
    strcpy(newNode->email, email);
    newNode->next = NULL;

    if (*start == NULL){
        *start = newNode;
        return;
    }

    node* temp = *start;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

int deleteEmail(node** start, char email[]){
    if (*start == NULL) return 0;

    node* temp = *start;
    if (strcmp(temp->email, email) == 0){
        *start = temp->next;
        free(temp);
        return 1;
    }

    while (temp->next != NULL && strcmp(temp->next->email, email) != 0)
        temp = temp->next;

    if (temp->next == NULL) return 0;
    node* deletedNode = temp->next;
    temp->next = deletedNode->next;
    free(deletedNode);

    return 1;
}

void printEmails(node* start){
    if (start == NULL){
        printf("Mailing list is empty.\n");
        return;
    }
    printf("Mailing list:\n");
    while (start != NULL){
        printf("%s\n", start->email);
        start = start->next;
    }
}

void saveToFile(node* start, char filename[]){
    FILE *fp;
    fp = fopen(filename, "w");

    if (fp == NULL){
        printf("Error opening file.\n");
        return;
    }

    while (start != NULL){
        fprintf(fp, "%s\n", start->email);
        start = start->next;
    }

    printf("Mailing list saved to file successfully.\n");
    fclose(fp);
}

void loadFromFile(node** start, char filename[]){
    FILE* fp;
    fp = fopen(filename, "r");

    if (fp == NULL){
        printf("Error opening file.\n");
        return;
    }

    char email[MAX];
    while (fgets(email, MAX, fp) != NULL){
        if (email[strlen(email) - 1] == '\n')
            email[strlen(email) - 1] = '\0';
        addEmail(start, email);
    }

    printf("Mailing list loaded from file successfully.\n");
    fclose(fp);
}

int main(){
    char filename[MAX];
    char email[MAX];
    int choice;
    node* start = NULL;

    printf("**********Mailing List Manager**********\n");

    while (1){
        printf("\nChoose from the following options:\n");
        printf("1. Add an email address to the mailing list.\n");
        printf("2. Delete an email address from the mailing list.\n");
        printf("3. Print the mailing list.\n");
        printf("4. Save the mailing list to a file.\n");
        printf("5. Load the mailing list from a file.\n");
        printf("6. Exit.\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice){
        case 1:
            printf("\nEnter the email address: ");
            scanf("%s", email);
            addEmail(&start, email);
            printf("Email added successfully.\n");
            break;

        case 2:
            printf("\nEnter the email address to delete: ");
            scanf("%s", email);
            if (deleteEmail(&start, email))
                printf("Email deleted successfully.\n");
            else
                printf("Email not found.\n");
            break;

        case 3:
            printEmails(start);
            break;

        case 4:
            printf("\nEnter the filename to save the mailing list to: ");
            scanf("%s", filename);
            saveToFile(start, filename);
            break;

        case 5:
            printf("\nEnter the filename to load the mailing list from: ");
            scanf("%s", filename);
            loadFromFile(&start, filename);
            break;

        case 6:
            printf("\nExiting program.\n");
            exit(0);

        default:
            printf("\nInvalid choice, please try again.\n");
            break;
        }
    }
    return 0;
}