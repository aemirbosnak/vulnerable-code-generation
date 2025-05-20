//FormAI DATASET v1.0 Category: Database simulation ; Style: thoughtful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_NAME_LENGTH 20
#define MAX_ADDRESS_LENGTH 50

struct student {
    int id;
    char name[MAX_NAME_LENGTH];
    char address[MAX_ADDRESS_LENGTH];
    float gpa;
};

int main(){
    int n;
    printf("Enter the number of students: ");
    scanf("%d",&n);
    struct student s[n];

    // Taking input from the user for each student
    for(int i=0;i<n;i++){
        printf("\nEnter details for student %d:\n",i+1);
        printf("ID: ");
        scanf("%d",&s[i].id);
        printf("Name: ");
        scanf("%s",s[i].name);
        printf("Address: ");
        scanf("%s",s[i].address);
        printf("GPA: ");
        scanf("%f",&s[i].gpa);
    }

    // Displaying the student details
    printf("\nStudent Details:\n");
    printf("ID\tName\t\tAddress\t\tGPA\n");
    for(int i=0;i<n;i++){
        printf("%d\t%s\t\t%s\t\t%.2f\n",s[i].id,s[i].name,s[i].address,s[i].gpa);
    }

    // Searching for a student by ID
    int search_id;
    printf("\nEnter ID to search for: ");
    scanf("%d",&search_id);
    int flag = 0;
    for(int i=0;i<n;i++){
        if(s[i].id == search_id){
            printf("Student Details found:\n");
            printf("ID\tName\t\tAddress\t\tGPA\n");
            printf("%d\t%s\t\t%s\t\t%.2f\n",s[i].id,s[i].name,s[i].address,s[i].gpa);
            flag = 1;
            break;
        }
    }
    if(flag == 0){
        printf("Student with ID %d not found.\n",search_id);
    }

    // Sorting the students by GPA
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(s[j].gpa > s[j+1].gpa){
                struct student temp = s[j];
                s[j] = s[j+1];
                s[j+1] = temp;
            }
        }
    }

    // Displaying the sorted student details
    printf("\nSorted Student Details (by GPA):\n");
    printf("ID\tName\t\tAddress\t\tGPA\n");
    for(int i=0;i<n;i++){
        printf("%d\t%s\t\t%s\t\t%.2f\n",s[i].id,s[i].name,s[i].address,s[i].gpa);
    }

    return 0;
}