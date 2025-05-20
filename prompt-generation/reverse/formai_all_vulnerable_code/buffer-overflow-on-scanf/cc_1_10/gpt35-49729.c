//FormAI DATASET v1.0 Category: Database querying ; Style: curious
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student {
    int id;
    char name[20];
    float cgpa;
};

int main() {
    struct student s[3] = {{1, "Alice", 9.2},
                           {2, "Bob", 8.6}, 
                           {3, "Charlie", 7.8}};
    
    int choice;
    printf("Enter choice:\n 1. Search student by ID\n 2. Search student by Name\n");
    scanf("%d", &choice);
    
    switch(choice) {
        case 1: {
            int id, flag=0;
            printf("Enter ID: ");
            scanf("%d",&id);
            for(int i=0; i<3; i++){
                if(s[i].id==id){
                    printf("\nID: %d\nName: %s\nCGPA: %.2f\n", s[i].id, s[i].name, s[i].cgpa);
                    flag=1;
                    break;
                }
            }
            if(!flag)
                printf("No student found with this ID");
            break;
        }
        case 2: {
            char name[20]; 
            int flag=0;
            printf("Enter Name: ");
            scanf("%s",name);
            for(int i=0; i<3; i++){
                if(strcmp(s[i].name,name)==0){
                    printf("\nID: %d\nName: %s\nCGPA: %.2f\n", s[i].id, s[i].name, s[i].cgpa);
                    flag=1;
                    break;
                }
            }
            if(!flag)
                printf("No student found with this Name");
            break;
        }
        default: {
            printf("Invalid Choice");
        }
    }

  return 0;
}