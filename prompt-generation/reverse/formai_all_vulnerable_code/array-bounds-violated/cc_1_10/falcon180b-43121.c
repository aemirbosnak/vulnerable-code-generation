//Falcon-180B DATASET v1.0 Category: File handling ; Style: peaceful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

typedef struct {
    char name[20];
    char address[50];
    char phone[15];
}person;

void main() {
    FILE *fptr;
    char ch;
    int i=0,j;
    person p[50];

    fptr = fopen("records.txt","r"); //open the file records.txt in read mode

    if(fptr==NULL) {
        printf("File not found!");
        exit(0);
    }

    while((ch=fgetc(fptr))!=EOF) { //read the file until end of file is reached
        if(ch=='\n') { //if newline character is encountered, it means an entire record has been read
            p[i].name[j]='\0'; //add null terminator to name string
            j=0; //reset j for the next record
        }
        else {
            if(isalpha(ch)) { //if the character is an alphabet, add it to the name string
                p[i].name[j++]=tolower(ch);
            }
            else if(ch==' ') { //if the character is a space, it means the name string is complete and now the address string starts
                j=0; //reset j for the address string
            }
        }
        i++; //increment i for the next record
    }

    fclose(fptr); //close the file

    fptr = fopen("records.txt","w"); //open the file records.txt in write mode

    if(fptr==NULL) {
        printf("File not found!");
        exit(0);
    }

    for(i=0;i<50;i++) { //loop through all the records
        if(p[i].name[0]!='\0') { //if the record is not empty
            fprintf(fptr,"%s %s %s\n",p[i].name,p[i].address,p[i].phone); //write the record to the file
        }
    }

    fclose(fptr); //close the file

    printf("File updated successfully!"); //display a success message
}