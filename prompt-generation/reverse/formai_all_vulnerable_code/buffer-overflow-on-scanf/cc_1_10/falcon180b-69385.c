//Falcon-180B DATASET v1.0 Category: File handling ; Style: cheerful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX 100

void main()
{
    FILE *fp;
    char ch;
    int i=0,j=0,k=0,l=0,m=0;
    char name[20];
    char address[30];
    char phone_number[15];
    char email_id[30];
    char password[15];

    struct employee
    {
        char name[20];
        char address[30];
        char phone_number[15];
        char email_id[30];
        char password[15];
    }emp;

    fp=fopen("employee.dat","a+");

    if(fp==NULL)
    {
        printf("\nFile does not exist!");
        exit(0);
    }

    printf("\nEnter the name of the employee: ");
    scanf("%s",emp.name);

    printf("\nEnter the address of the employee: ");
    scanf("%s",emp.address);

    printf("\nEnter the phone number of the employee: ");
    scanf("%s",emp.phone_number);

    printf("\nEnter the email id of the employee: ");
    scanf("%s",emp.email_id);

    printf("\nEnter the password of the employee: ");
    scanf("%s",emp.password);

    fseek(fp,0,SEEK_END);

    while(fgetc(fp)!=EOF)
    {
        i++;
    }

    rewind(fp);

    for(j=0;j<i;j++)
    {
        fscanf(fp,"%s %s %s %s %s",&name[j],&address[j],&phone_number[j],&email_id[j],&password[j]);

        if(strcmp(name[j],emp.name)==0 && strcmp(address[j],emp.address)==0 && strcmp(phone_number[j],emp.phone_number)==0 && strcmp(email_id[j],emp.email_id)==0 && strcmp(password[j],emp.password)==0)
        {
            printf("\nEmployee already exists!");
            exit(0);
        }
    }

    fprintf(fp,"%s %s %s %s %s\n",emp.name,emp.address,emp.phone_number,emp.email_id,emp.password);

    printf("\nEmployee added successfully!");

    fclose(fp);
}