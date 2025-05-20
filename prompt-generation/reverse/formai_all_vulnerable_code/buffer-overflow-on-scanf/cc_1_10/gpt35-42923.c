//FormAI DATASET v1.0 Category: Online Examination System ; Style: real-life
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Structure for student record
struct student{
    int roll_no;
    char name[20];
    float score;
};

//Function to add student record
void add_record(struct student s[], int* n){
    printf("\nEnter Student's Roll No: ");
    scanf("%d", &s[*n].roll_no);
    printf("\nEnter Student's Name: ");
    scanf("%s", s[*n].name);
    printf("\nEnter Student's Score: ");
    scanf("%f", &s[*n].score);
    
    (*n)++; //Incrementing the size of record array
    printf("\nRecord added successfully!\n");
}

//Function to display student record
void display_record(struct student s[], int n){
    if(n<=0){
        printf("\nThe record is empty!\n");
        return;
    }
    printf("\nRoll No\t Name\t Score\n");
    printf("__________________________________\n");
    for(int i=0; i<n; i++){
        printf("%d\t %s\t %.2f\n", s[i].roll_no, s[i].name, s[i].score);
    }
}

//Main function
int main(){
    struct student record[100]; //Max size 100 records
    int size=0, choice;
    
    printf("Online Examination System\n");
    printf("_____________________________\n");
    
    //Menu Driven program
    do{
        printf("\nChoose your action:\n");
        printf("1. Add Record\n2. Display Records\n3. Exit\n");
        printf("_____________________________\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice){
            case 1: add_record(record, &size);
                    break;
            case 2: display_record(record, size);
                    break;
            case 3: printf("\nThank you for using our program!\n");
                    exit(0);
                    break;
            default: printf("\nInvalid Choice! Try Again.\n");
        }
    }while(1);
    
    return 0;
}