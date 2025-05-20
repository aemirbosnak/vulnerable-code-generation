//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CATEGORIES 20
#define MAX_ENTRIES 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    float amount;
} Expense;

typedef struct {
    char name[NAME_LENGTH];
    Expense expenses[MAX_ENTRIES];
    int expense_count;
} Category;

typedef struct {
    Category categories[MAX_CATEGORIES];
    int category_count;
} PersonalFinance;

void add_category(PersonalFinance *pf) {
    if (pf->category_count >= MAX_CATEGORIES) {
        printf("Maximum category limit reached.\n");
        return;
    }
    
    printf("Enter category name: ");
    scanf("%s", pf->categories[pf->category_count].name);
    pf->categories[pf->category_count].expense_count = 0;
    pf->category_count++;
    printf("Category added successfully!\n");
}

void add_expense(PersonalFinance *pf) {
    char category_name[NAME_LENGTH];
    printf("Enter category name to add expense: ");
    scanf("%s", category_name);
    
    for (int i = 0; i < pf->category_count; i++) {
        if (strcmp(pf->categories[i].name, category_name) == 0) {
            if (pf->categories[i].expense_count >= MAX_ENTRIES) {
                printf("Maximum expense limit reached for this category.\n");
                return;
            }
            
            printf("Enter expense name: ");
            scanf("%s", pf->categories[i].expenses[pf->categories[i].expense_count].name);
            printf("Enter expense amount: ");
            scanf("%f", &pf->categories[i].expenses[pf->categories[i].expense_count].amount);
            pf->categories[i].expense_count++;
            printf("Expense added successfully!\n");
            return;
        }
    }
    
    printf("Category not found.\n");
}

void display_summary(PersonalFinance *pf) {
    printf("Personal Finance Summary:\n");
    for (int i = 0; i < pf->category_count; i++) {
        printf("Category: %s\n", pf->categories[i].name);
        float total = 0;
        for (int j = 0; j < pf->categories[i].expense_count; j++) {
            printf("  Expense: %s, Amount: %.2f\n", pf->categories[i].expenses[j].name, pf->categories[i].expenses[j].amount);
            total += pf->categories[i].expenses[j].amount;
        }
        printf("Total for %s: %.2f\n\n", pf->categories[i].name, total);
    }
}

void save_to_file(PersonalFinance *pf) {
    FILE *file = fopen("personal_finance.txt", "w");
    if (!file) {
        printf("Could not open file for writing.\n");
        return;
    }
    
    for (int i = 0; i < pf->category_count; i++) {
        fprintf(file, "Category: %s\n", pf->categories[i].name);
        for (int j = 0; j < pf->categories[i].expense_count; j++) {
            fprintf(file, "  Expense: %s, Amount: %.2f\n", pf->categories[i].expenses[j].name, pf->categories[i].expenses[j].amount);
        }
        fprintf(file, "\n");
    }
    
    fclose(file);
    printf("Data saved to personal_finance.txt.\n");
}

int main() {
    PersonalFinance pf;
    pf.category_count = 0;
    int choice;
    
    do {
        printf("\nPersonal Finance Planner\n");
        printf("1. Add Category\n");
        printf("2. Add Expense\n");
        printf("3. Display Summary\n");
        printf("4. Save to File\n");
        printf("5. Exit\n");
        
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_category(&pf);
                break;
            case 2:
                add_expense(&pf);
                break;
            case 3:
                display_summary(&pf);
                break;
            case 4:
                save_to_file(&pf);
                break;
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 5);
    
    return 0;
}