//FormAI DATASET v1.0 Category: Database querying ; Style: Romeo and Juliet
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct character{
    char name[20];
    int age;
    char gender;
    char role[20];
    char quote[100];
};

void query(char *field, char *value, int count, struct character arr[]){
    int i;
    int flag=0;
    for(i=0;i<count;i++){
        if(strcmp(field, "name")==0){
            if(strcmp(arr[i].name, value)==0){
                printf("%s: \"%s\"\n", arr[i].name, arr[i].quote);
                flag=1;
                break;
            }
        }
        else if(strcmp(field, "role")==0){
            if(strcmp(arr[i].role, value)==0){
                printf("%s: \"%s\"\n", arr[i].name, arr[i].quote);
                flag=1;
                break;
            }
        }
        else if(strcmp(field, "gender")==0){
            if(arr[i].gender==*value){
                printf("%s: \"%s\"\n", arr[i].name, arr[i].quote);
                flag=1;
            }
        }
        else if(strcmp(field, "age")==0){
            int age = atoi(value);
            if(arr[i].age==age){
                printf("%s: \"%s\"\n", arr[i].name, arr[i].quote);
                flag=1;
            }
        }
    }
    if(flag==0)
        printf("I couldn't find any quotes matching that query. Sorry!\n");
}

int main(){
    printf("Welcome to the Romeo and Juliet Database.\n");
    printf("Please enter the number of characters you would like to input and query: ");
    int count;
    scanf("%d", &count);
    struct character arr[count];
    int i;
    for(i=0;i<count;i++){
        printf("\nPlease enter the details for character %d:\n", i+1);
        printf("Name: ");
        scanf("%s", arr[i].name);
        printf("Age: ");
        scanf(" %d", &arr[i].age);
        printf("Gender (M/F): ");
        scanf(" %c", &arr[i].gender);
        printf("Role: ");
        scanf("%s", arr[i].role);
        printf("Famous quote: ");
        scanf(" %[^\n]s", arr[i].quote);
    }
    char selection[10];
    while(strcmp(selection, "exit")!=0){
        printf("\nWhat field would you like to query by (name, gender, age, role)?\n");
        scanf("%s", selection);
        if(strcmp(selection, "exit")==0)
            break;
        char value[20];
        printf("What value are you looking for?\n");
        scanf("%s", value);
        query(selection, value, count, arr);
    }
    printf("\nThank you for using the Romeo and Juliet Database!\n");
    return 0;
}