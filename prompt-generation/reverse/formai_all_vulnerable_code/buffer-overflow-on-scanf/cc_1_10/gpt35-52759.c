//FormAI DATASET v1.0 Category: File handling ; Style: thoughtful
#include <stdio.h>

int main() {
    FILE *fp;
    char filename[20], text[100], ch;
    int choice, count, lines;

    printf("What operation do you want to perform?\n\n");
    printf("1. Create a file\n2. Write to a file\n3. Read a file\n4. Count number of lines in a file\n5. Exit\n\nEnter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("\nEnter file name: ");
            scanf("%s", filename);
            fp = fopen(filename, "w");
            printf("\nFile created successfully!");
            fclose(fp);
            break;
            
        case 2:
            printf("\nEnter file name: ");
            scanf("%s", filename);
            
            fp = fopen(filename, "a");

            printf("\nWhat do you want to write to the file? ");
            getchar(); // to consume the newline character left by scanf()
            fgets(text, 100, stdin);

            fprintf(fp, "%s", text);
            printf("\nText written to file successfully!");
            
            fclose(fp);
            break;
            
        case 3:
            printf("\nEnter file name: ");
            scanf("%s", filename);

            fp = fopen(filename, "r");

            printf("\nContents of the file are:\n\n");
            ch = getc(fp);
            while(ch != EOF) {
                printf("%c", ch);
                ch = getc(fp);
            }

            fclose(fp);
            break;

        case 4:
            printf("\nEnter file name: ");
            scanf("%s", filename);

            fp = fopen(filename, "r");

            count = 0;
            while((ch = fgetc(fp)) != EOF) {
                if(ch == '\n') {
                    count++;
                }
            }

            printf("\nThe number of lines in the file is: %d", count+1);

            fclose(fp);
            break;

        case 5:
            printf("\nExiting program...");
            break;

        default:
            printf("\nInvalid choice!");
    }

    return 0;
}