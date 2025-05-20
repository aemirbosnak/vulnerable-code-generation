//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Romeo and Juliet
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define MAX 1000

char string1[MAX];
char string2[MAX];
int count1=0,count2=0;
int len1,len2;

void read_file(char *filename, char *string) {
    FILE *fp;
    fp=fopen(filename,"r");
    if(fp==NULL) {
        printf("Error opening file.\n");
        exit(0);
    }
    fgets(string,MAX,fp);
    fclose(fp);
}

void display_menu() {
    printf("\n");
    printf("1. Enter two DNA sequences\n");
    printf("2. Compare two DNA sequences\n");
    printf("3. Exit\n");
    printf("\n");
}

int main() {
    int choice;
    char ch;

    do {
        system("clear");
        display_menu();
        scanf("%d",&choice);
        getchar();
        switch(choice) {
            case 1:
                printf("Enter first DNA sequence: ");
                scanf("%s",string1);
                printf("Enter second DNA sequence: ");
                scanf("%s",string2);
                break;
            case 2:
                printf("Comparing %s and %s...\n",string1,string2);
                if(strcmp(string1,string2)==0) {
                    printf("The two DNA sequences are identical.\n");
                }
                else {
                    printf("The two DNA sequences are different.\n");
                }
                break;
            case 3:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
        printf("\n");
        printf("Do you want to continue? (y/n): ");
        scanf(" %c",&ch);
        getchar();
    } while(ch=='y' || ch=='Y');

    return 0;
}