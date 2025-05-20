//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Knight{
    char name[20];
    int age;
    float income;
    float expenses;
};

void add_knight(struct Knight *arr, int size){
    printf("Enter name of knight: ");
    scanf("%s", arr[size].name);
    printf("Enter age of knight: ");
    scanf("%d", &arr[size].age);
    printf("Enter income of knight: ");
    scanf("%f", &arr[size].income);
    printf("Enter expenses of knight: ");
    scanf("%f", &arr[size].expenses);
}

void print_knights(struct Knight *arr, int size){
    for(int i=0;i<size;i++){
        printf("Name: %s\nAge: %d\nIncome: %f\nExpenses: %f\n\n", arr[i].name, arr[i].age, arr[i].income, arr[i].expenses);
    }
}

void save_knights(struct Knight *arr, int size){
    FILE *fp = fopen("knights.txt", "w");
    for(int i=0;i<size;i++){
        fprintf(fp, "%s,%d,%f,%f\n", arr[i].name, arr[i].age, arr[i].income, arr[i].expenses);
    }
    fclose(fp);
}

void load_knights(struct Knight *arr, int *size){
    FILE *fp = fopen("knights.txt", "r");
    if(fp==NULL){
        printf("File not found!\n");
        return;
    }
    while(!feof(fp)){
        fscanf(fp, "%[^,],%d,%f,%f\n", arr[*size].name, &arr[*size].age, &arr[*size].income, &arr[*size].expenses);
        (*size)++;
    }
    fclose(fp);
}

void analyze_knights(struct Knight *arr, int size){
    float total_income=0, total_expenses=0;
    int young_count=0, old_count=0;
    for(int i=0;i<size;i++){
        total_income += arr[i].income;
        total_expenses += arr[i].expenses;
        if(arr[i].age<30){
            young_count++;
        }
        else{
            old_count++;
        }
    }
    printf("Total Income: %f\nTotal Expenses: %f\nYoung Knights: %d\nOld Knights: %d\n", total_income, total_expenses, young_count, old_count);
}

int main(){
    struct Knight knights[10];
    int size=0, choice;
    do{
        printf("\nMedieval Personal Finance Planner\n");
        printf("1. Add Knight\n");
        printf("2. View Knights\n");
        printf("3. Save Knights to File\n");
        printf("4. Load Knights from File\n");
        printf("5. Analyze Knights\n");
        printf("6. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                add_knight(knights, size);
                size++;
                break;
            case 2:
                print_knights(knights, size);
                break;
            case 3:
                save_knights(knights, size);
                break;
            case 4:
                load_knights(knights, &size);
                break;
            case 5:
                analyze_knights(knights, size);
                break;
            case 6:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }while(choice!=6);
    return 0;
}