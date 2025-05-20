//Falcon-180B DATASET v1.0 Category: File handling ; Style: romantic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>

#define MAX 100

typedef struct{
    char name[20];
    char address[50];
    char phone[15];
}person;

void add(person *p){
    printf("Enter name: ");
    scanf("%s",p->name);
    printf("Enter address: ");
    scanf("%s",p->address);
    printf("Enter phone number: ");
    scanf("%s",p->phone);
}

void display(person p){
    printf("\nName: %s",p.name);
    printf("\nAddress: %s",p.address);
    printf("\nPhone number: %s",p.phone);
}

int main(){
    FILE *fp;
    char ch;
    person p[MAX];
    int count=0;
    printf("Enter file name: ");
    scanf("%s",ch);

    fp=fopen(ch,"a+");

    if(fp==NULL){
        printf("\nFile does not exist!");
        exit(0);
    }

    while(fscanf(fp,"%s %s %s",p[count].name,p[count].address,p[count].phone)!=EOF){
        count++;
    }

    rewind(fp);

    printf("\n\nName\tAddress\t\tPhone number");
    for(int i=0;i<count;i++){
        display(p[i]);
    }

    while(true){
        printf("\n\n1.Add record");
        printf("\n2.Display record");
        printf("\n3.Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&ch);

        switch(ch){
            case 1:
                if(count>=MAX){
                    printf("\nFile is full!");
                }
                else{
                    add(&p[count]);
                    fseek(fp,0,SEEK_END);
                    fprintf(fp,"%s %s %s",p[count].name,p[count].address,p[count].phone);
                    count++;
                    fclose(fp);
                    fp=fopen(ch,"a+");
                    rewind(fp);
                }
                break;

            case 2:
                rewind(fp);
                printf("\n\nName\tAddress\t\tPhone number");
                for(int i=0;i<count;i++){
                    display(p[i]);
                }
                break;

            case 3:
                exit(0);

            default:
                printf("\nInvalid choice!");
        }
    }

    return 0;
}