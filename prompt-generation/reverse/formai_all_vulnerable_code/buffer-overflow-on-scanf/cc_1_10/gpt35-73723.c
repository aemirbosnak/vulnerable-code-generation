//FormAI DATASET v1.0 Category: File handling ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *fileptr;
    char filename[50], ch;
    int choice;
    
    printf("Ah Romeo, will you not speak a word to me? Would you rather write code instead?\n");
    printf("Enter the file name you would like to create or modify: ");
    scanf("%s",filename);

    fileptr = fopen(filename,"r");

    if (fileptr == NULL) {
        printf("Alas, the file does not exist, shall I create it for you? (Yes - 1, No - 0)");
        scanf("%d", &choice);
        if(choice==1) {
            fileptr = fopen(filename,"w");
            printf("You shall have a new crafted file, my sweet.\n");
            exit(0);
        }
        else {
            printf("Then wherefore art thou here?\n");
            exit(0);
        }
    }

    printf("What would you like to do with the file my love? (Read - 1, Write - 2): ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Thus with a kiss I die, if you insist on reading, here is the content of the file:\n");
        while ((ch = fgetc(fileptr)) != EOF) {
            printf("%c", ch);
        }
        fclose(fileptr);
    }

    else if (choice == 2) {
        printf("My bounty is as boundless as the sea, the more you write the more I desire - what would you like to write to the file?: \n");
        fileptr = fopen(filename,"a");
        while((ch=getchar())!= EOF){
          if(ch=='\n')
          break;
          else
          fputc(ch,fileptr);
        }
        fclose(fileptr);
        printf("Your words have given me new life.\n");
    }

    else {
        printf("O Romeo, Romeo! Wherefore art thou Romeo? Deny thy choice, and refuse thy choice. Shall I take my leave?\n");
        exit(0);
    }

    return 0;
}