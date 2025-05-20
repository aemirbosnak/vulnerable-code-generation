//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: accurate
#include<stdio.h>
#include<string.h>
#define MAX 1000

struct expense {
    char category[20];
    float amount;
}ex;

void addExpense(FILE *f);

void viewAllExpense(FILE *f);

void viewExpenseCategory(FILE *f);

void editExpense(FILE *f);

void deleteExpense(FILE *f);

int main() {
    
    FILE *fp;
    
    int choice;

    char password[MAX];
    
    printf("Enter Password:");
    
    gets(password);
    
    if(strcmp(password, "PersonalFinancePlanner") == 0) {
        

        printf("1. Add Expense\n");
        printf("2. View All Expenses\n");
        printf("3. View Expense by Category\n");
        printf("4. Edit Expense\n");
        printf("5. Delete Expense\n");
        printf("6. Exit\n");
        
        printf("Enter Your Choice:");
        scanf("%d", &choice);
        
        switch(choice) {
            
            case 1:
                addExpense(fp);
                break;
            case 2:
                viewAllExpense(fp);
                break;
            case 3:
                viewExpenseCategory(fp);
                break;
            case 4:
                editExpense(fp);
                break;
            case 5:
                deleteExpense(fp);
                break;
            default:
                printf("Invalid Choice!");
        }
        
            
    }
    else {
        printf("Invalid Password!");
    }
    
    return 0;
}

void addExpense(FILE *f) {
    
    f = fopen("expense.txt", "a");
    
    printf("Enter Expense Category:");
    fflush(stdin);
    gets(ex.category);
    
    printf("Enter Expense Amount:");
    scanf("%f", &ex.amount);
    
    fprintf(f, "%s %f\n", ex.category, ex.amount);
    
    fclose(f);
    
    printf("Expense Added Successfully!\n\n");
        
}

void viewAllExpense(FILE *f) {
    
    float total = 0;
    
    f = fopen("expense.txt", "r");
    
    printf("Expense Category\t\tExpense Amount\n\n");
    
    while(fscanf(f, "%s %f", ex.category, &ex.amount) != EOF) {
        
        printf("%s\t\t\t%.2f\n", ex.category, ex.amount);
        
        total += ex.amount;
    }
    
    printf("\nTotal Expense:\t\t\t%.2f\n\n", total);
    
    fclose(f);
}

void viewExpenseCategory(FILE *f) {
    
    float total = 0;
    char cat[20];
    int found = 0;

    f = fopen("expense.txt", "r");
    
    printf("Enter Expense Category:");
    fflush(stdin);
    gets(cat);
    
    printf("Expense Category\t\tExpense Amount\n\n");
    
    while(fscanf(f, "%s %f", ex.category, &ex.amount) != EOF) {
        
        if(strcmp(cat, ex.category) == 0) {
            
            printf("%s\t\t\t%.2f\n", ex.category, ex.amount);
            
            total += ex.amount;
            found = 1;
        }
    }
    
    if(found == 0) {
        printf("No Expense Found for this Category!\n");
    }
    else {
        printf("\nTotal Expense:\t\t\t%.2f\n\n", total);
    }
    
    fclose(f);
}

void editExpense(FILE *f) {
    
    char cat[20], ch;
    float amt;
    int found = 0;

    f = fopen("expense.txt", "r");
    
    FILE *fp;
    
    fp = fopen("temp.txt", "w");
    
    printf("Enter Expense Category to Edit:");
    fflush(stdin);
    gets(cat);
    
    while(fscanf(f, "%s %f", ex.category, &ex.amount) != EOF) {
        
        if(strcmp(cat, ex.category) == 0) {
            
            found = 1;
            
            printf("Expense Category\t\tExpense Amount\n\n");
            printf("%s\t\t\t%.2f\n", ex.category, ex.amount);
            
            printf("Enter New Expense Category or press Enter to skip:");
            fflush(stdin);
            ch = getchar();
            if(ch != '\n') {
                ungetc(ch, stdin);
                gets(ex.category);
            }
            
            printf("Enter New Expense Amount or press Enter to skip:");
            scanf("%f", &amt);
            if(amt != '\n') {
                ex.amount = amt;
            }
            
            fprintf(fp, "%s %.2f\n", ex.category, ex.amount);
            
            printf("Expense Edited Successfully!\n");
        }
        else {
            fprintf(fp, "%s %.2f\n", ex.category, ex.amount);
        }
    }
    
    if(found == 0) {
        printf("Expense Category Not Found!");
    }
    
    fclose(fp);
    fclose(f);
    
    remove("expense.txt");
    rename("temp.txt", "expense.txt");
}

void deleteExpense(FILE *f) {
    
    char cat[20];
    int found = 0;

    f = fopen("expense.txt", "r");
    
    FILE *fp;
    
    fp = fopen("temp.txt", "w");
    
    printf("Enter Expense Category to Delete:");
    fflush(stdin);
    gets(cat);
    
    while(fscanf(f, "%s %f", ex.category, &ex.amount) != EOF) {
        
        if(strcmp(cat, ex.category) == 0) {
            
            found = 1;
            
            printf("Expense Category\t\tExpense Amount\n\n");
            printf("%s\t\t\t%.2f\n", ex.category, ex.amount);
            
            printf("Expense Deleted Successfully!\n");
        }
        else {
            fprintf(fp, "%s %.2f\n", ex.category, ex.amount);
        }
    }
    
    if(found == 0) {
        printf("Expense Category Not Found!");
    }
    
    fclose(fp);
    fclose(f);
    
    remove("expense.txt");
    rename("temp.txt", "expense.txt");
}