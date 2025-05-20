//Falcon-180B DATASET v1.0 Category: File handling ; Style: sophisticated
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX 100

// Structure for student
struct student{
    char name[50];
    int age;
    float marks;
};

// Function to read data from file
void readData(FILE *fp, struct student s[], int n){
    int i=0;
    while(fscanf(fp,"%s %d %f",s[i].name,&s[i].age,&s[i].marks)!=EOF){
        i++;
    }
    n=i;
}

// Function to write data to file
void writeData(FILE *fp, struct student s[], int n){
    int i;
    for(i=0;i<n;i++){
        fprintf(fp,"%s %d %f\n",s[i].name,s[i].age,s[i].marks);
    }
}

// Function to sort array based on marks
void sort(struct student s[], int n){
    int i,j;
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            if(s[i].marks<s[j].marks){
                struct student temp;
                temp=s[i];
                s[i]=s[j];
                s[j]=temp;
            }
        }
    }
}

int main(){
    FILE *fp;
    char filename[50];
    int choice,n;
    struct student s[MAX];

    printf("Enter the filename: ");
    scanf("%s",filename);

    fp=fopen(filename,"r");
    if(fp==NULL){
        printf("File not found\n");
        exit(0);
    }

    printf("Enter the number of records: ");
    scanf("%d",&n);

    readData(fp,s,n);

    printf("\nName\tAge\tMarks\n");
    for(int i=0;i<n;i++){
        printf("%s\t%d\t%.2f\n",s[i].name,s[i].age,s[i].marks);
    }

    printf("\nEnter your choice:\n1.Sort by marks\n2.Write to file\n");
    scanf("%d",&choice);

    switch(choice){
        case 1:
            sort(s,n);
            printf("\nSorted by marks:\n");
            for(int i=0;i<n;i++){
                printf("%s\t%d\t%.2f\n",s[i].name,s[i].age,s[i].marks);
            }
            break;

        case 2:
            writeData(fp,s,n);
            printf("\nData written to file\n");
            break;

        default:
            printf("Invalid choice\n");
    }

    fclose(fp);
    return 0;
}