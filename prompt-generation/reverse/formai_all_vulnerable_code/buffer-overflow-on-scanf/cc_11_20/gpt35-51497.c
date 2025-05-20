//FormAI DATASET v1.0 Category: Data recovery tool ; Style: multivariable
#include<stdio.h>
#include<string.h>

struct student{
   char name[50];
   int roll;
   float marks;
};

int main(){
    struct student s[100];
    int n,i,j;
    printf("Enter number of records:");
    scanf("%d",&n);

    for(i=0;i<n;i++){
       printf("\nEnter name:");
       scanf("%s",&s[i].name);

       printf("Enter roll number:");
       scanf("%d",&s[i].roll);

       printf("Enter marks:");
       scanf("%f",&s[i].marks);
    }

    int option;
    printf("\nPress 1 to recover data by Roll Number\n");
    printf("Press 2 to recover data by Name\n");
    printf("Press 3 to recover data by Marks\n");
    scanf("%d",&option);

    if(option==1){
        int r;
        printf("\nEnter roll number to recover data:");
        scanf("%d",&r);
        for(i=0;i<n;i++){
            if(s[i].roll==r){
               printf("\nDetails of Roll Number %d are:\n",s[i].roll);
               printf("Name: %s\n",s[i].name);
               printf("Marks: %.2f\n",s[i].marks);
            }
        }
    }
    else if(option==2){
        char name[50];
        printf("\nEnter name to recover data:");
        scanf("%s",name);
        for(i=0;i<n;i++){
            if(strcmp(s[i].name,name)==0){
               printf("\nDetails of %s are:\n",s[i].name);
               printf("Roll Number: %d\n",s[i].roll);
               printf("Marks: %.2f\n",s[i].marks);
            }
        }
    }
    else if(option==3){
        float m;
        printf("\nEnter marks to recover data:");
        scanf("%f",&m);
        for(i=0;i<n;i++){
            if(s[i].marks==m){
               printf("\nDetails for marks %.2f are:\n",s[i].marks);
               printf("Name: %s\n",s[i].name);
               printf("Roll Number: %d\n",s[i].roll);
            }
        }
    }
    else{
        printf("\nInvalid option selected. Please try again!\n");
    }
    return 0;
}