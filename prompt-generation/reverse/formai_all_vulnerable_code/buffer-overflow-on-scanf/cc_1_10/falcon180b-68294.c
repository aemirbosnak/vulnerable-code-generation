//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_WEIGHTS 100

typedef struct{
    char name[50];
    int age;
    int weight;
    int height;
    char gender[10];
    char email[100];
    char phone[15];
    time_t join_date;
}User;

User users[MAX_USERS];
int num_users=0;

void signup(){
    char name[50];
    int age,weight,height;
    char gender[10];
    char email[100],phone[15];
    printf("Enter your name: ");
    scanf("%s",name);
    printf("Enter your age: ");
    scanf("%d",&age);
    printf("Enter your gender: ");
    scanf("%s",gender);
    printf("Enter your email: ");
    scanf("%s",email);
    printf("Enter your phone number: ");
    scanf("%s",phone);
    printf("Enter your weight in kg: ");
    scanf("%d",&weight);
    printf("Enter your height in cm: ");
    scanf("%d",&height);
    strcpy(users[num_users].name,name);
    users[num_users].age=age;
    strcpy(users[num_users].gender,gender);
    strcpy(users[num_users].email,email);
    strcpy(users[num_users].phone,phone);
    users[num_users].weight=weight;
    users[num_users].height=height;
    users[num_users].join_date=time(NULL);
    num_users++;
}

void login(){
    char name[50];
    int i;
    printf("Enter your name: ");
    scanf("%s",name);
    for(i=0;i<num_users;i++){
        if(strcmp(users[i].name,name)==0){
            printf("Welcome %s! You joined on %s",users[i].name,ctime(&users[i].join_date));
            break;
        }
    }
}

void view_users(){
    int i;
    for(i=0;i<num_users;i++){
        printf("%s %d years old, %s, %d kg, %d cm, %s, %s, %s\n",users[i].name,users[i].age,users[i].gender,users[i].weight,users[i].height,users[i].email,users[i].phone,ctime(&users[i].join_date));
    }
}

void update_weight(){
    char name[50];
    int i;
    printf("Enter your name: ");
    scanf("%s",name);
    for(i=0;i<num_users;i++){
        if(strcmp(users[i].name,name)==0){
            printf("Enter your new weight in kg: ");
            scanf("%d",&users[i].weight);
            printf("Weight updated successfully!\n");
            break;
        }
    }
}

int main(){
    int choice;
    while(1){
        printf("\nFitness Tracker\n");
        printf("1. Signup\n2. Login\n3. View Users\n4. Update Weight\n5. Exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                signup();
                break;
            case 2:
                login();
                break;
            case 3:
                view_users();
                break;
            case 4:
                update_weight();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}