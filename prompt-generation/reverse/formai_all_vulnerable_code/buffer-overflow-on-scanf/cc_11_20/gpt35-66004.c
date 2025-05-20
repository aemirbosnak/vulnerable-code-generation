//FormAI DATASET v1.0 Category: File handling ; Style: rigorous
#include<stdio.h>
#include<stdlib.h>

int main() {
    FILE *fp;
    char filename[20], ch, buffer[200];
    int choice, count, pos;
    long length;
    
    while(1) {
        printf("\n1) Create a new file\n2) Write to file\n3) Read from file\n4) Search a character\n5) Exit\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Enter file name to create: ");
                scanf("%s", filename);
                fp = fopen(filename, "w");
                printf("\nBlank file \"%s\" created successfully!\n", filename);
                fclose(fp);
                break;
                
            case 2:
                printf("Enter file name to write: ");
                scanf("%s", filename);
                fp = fopen(filename, "a");
                printf("\nEnter data to write: ");
                scanf(" %[^\n]s", buffer);
                count = fprintf(fp, "%s\n", buffer);
                printf("\nData written successfully!\n");
                fclose(fp);
                break;
                
            case 3:
                printf("Enter file name to read: ");
                scanf("%s", filename);
                fp = fopen(filename, "r");
                fseek(fp, 0, SEEK_END);
                length = ftell(fp);
                fseek(fp, 0, SEEK_SET);
                printf("\nLength of file \"%s\" is %ld characters.\n\n", filename, length);
                while((ch = fgetc(fp)) != EOF) {
                    printf("%c", ch);
                }
                fclose(fp);
                break;
                
            case 4:
                printf("Enter file name to search: ");
                scanf("%s", filename);
                fp = fopen(filename, "r");
                printf("\nEnter character to search: ");
                scanf(" %c", &ch);
                pos = 0;
                while((ch = fgetc(fp)) != EOF) {
                    pos++;
                    if(ch == buffer[0]) {
                        printf("\n'%c' found at position %d in \"%s\" file.\n", buffer[0], pos, filename);
                        break;
                    }
                }
                if(pos == length) {
                    printf("\n'%c' not found in \"%s\" file.\n", buffer[0], filename);
                }
                fclose(fp);
                break;
                
            case 5:
                printf("\nExiting...\n");
                exit(0);
                
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }
    return 0;
}