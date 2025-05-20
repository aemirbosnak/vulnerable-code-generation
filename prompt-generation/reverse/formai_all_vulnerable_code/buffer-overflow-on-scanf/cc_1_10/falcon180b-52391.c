//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: surrealist
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<math.h>

//Function to check if a string is a valid number
int isnumber(char *str){
    int i;
    for(i=0;str[i]!='\0';i++){
        if(!isdigit(str[i]))
            return 0;
    }
    return 1;
}

//Function to calculate the total expense
float total_expense(float *expense,int size){
    float total=0;
    int i;
    for(i=0;i<size;i++){
        total+=expense[i];
    }
    return total;
}

//Function to display the expense report
void display_report(float *expense,int size){
    int i;
    printf("Expense Report:\n");
    for(i=0;i<size;i++){
        printf("Expense %d: %.2f\n",i+1,expense[i]);
    }
    printf("Total Expense: %.2f\n",total_expense(expense,size));
}

//Main function
int main(){
    int size,i;
    float *expense;

    //Get the number of expenses from the user
    printf("Enter the number of expenses: ");
    scanf("%d",&size);

    //Allocate memory for the expenses array
    expense=(float*)malloc(size*sizeof(float));

    //Get the expenses from the user
    for(i=0;i<size;i++){
        printf("Enter expense %d: ",i+1);
        scanf("%f",&expense[i]);
    }

    //Display the expense report
    display_report(expense,size);

    //Free the memory allocated for the expenses array
    free(expense);

    return 0;
}