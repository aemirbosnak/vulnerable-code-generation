//FormAI DATASET v1.0 Category: Expense Tracker ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct record {
    int id;
    int day;
    int month;
    int year;
    float amount;
    char category[20];
    char description[50];
};

void main_menu();
void add_record();
void view_records();
void search_records();

int count = 0;
struct record records[100];

int main() {
    
    main_menu();
    return 0;
}

void main_menu() {
    printf("\n\nWelcome to the Expense Tracker!\n\n");
    printf("1. Add Expense Record\n");
    printf("2. View Expense Records\n");
    printf("3. Search Expense Records\n");
    printf("4. Exit\n\n");
    printf("Enter your choice: ");
    
    int choice;
    scanf("%d", &choice);
    
    switch (choice) {
        case 1:
            add_record();
            break;
        case 2:
            view_records();
            break;
        case 3:
            search_records();
            break;
        case 4:
            printf("\nThanks for using Expense Tracker!\n");
            exit(0);
        default:
            printf("\nInvalid Choice! Try again.\n\n");
            main_menu();
    }
}

void add_record() {
    printf("\n\nAdd Expense Record\n\n");
    
    struct record temp;
    
    printf("Enter Expense ID: ");
    scanf("%d", &temp.id);
    
    printf("Enter Expense Date (DD MM YYYY): ");
    scanf("%d %d %d", &temp.day, &temp.month, &temp.year);
    
    printf("Enter Expense Amount: ");
    scanf("%f", &temp.amount);
    
    printf("Enter Expense Category: ");
    scanf("%s", temp.category);
    
    printf("Enter Expense Description: ");
    scanf("%s", temp.description);
    
    printf("\nExpense Record Added Successfully!\n\n");
    
    records[count] = temp;
    count++;
    
    main_menu();
}

void view_records() {
    printf("\n\nView Expense Records\n\n");
    
    if (count == 0) {
        printf("No Expense Record Found!\n\n");
        main_menu();
    }
    
    for (int i = 0; i < count; i++) {
        printf("ID: %d\n", records[i].id);
        printf("Date: %d-%d-%d\n", records[i].day, records[i].month, records[i].year);
        printf("Amount: %.2f\n", records[i].amount);
        printf("Category: %s\n", records[i].category);
        printf("Description: %s\n\n", records[i].description);
    }
    
    main_menu();
}

void search_records() {
    printf("\n\nSearch Expense Records\n\n");
    
    if (count == 0) {
        printf("No Expense Record Found!\n\n");
        main_menu();
    }
    
    printf("Enter Expense ID to Search: ");
    int id;
    scanf("%d", &id);
    
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (records[i].id == id) {
            found = 1;
            printf("\nExpense Record Found!\n\n");
            printf("ID: %d\n", records[i].id);
            printf("Date: %d-%d-%d\n", records[i].day, records[i].month, records[i].year);
            printf("Amount: %.2f\n", records[i].amount);
            printf("Category: %s\n", records[i].category);
            printf("Description: %s\n\n", records[i].description);
            break;
        }
    }
    
    if (!found) {
        printf("\nNo Expense Record Found for ID: %d\n\n", id);
    }
    
    main_menu();
}