//FormAI DATASET v1.0 Category: Data recovery tool ; Style: light-weight
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
    FILE *fp;
    char filename[100], ch, data[100000];
    int choice, size, i;

    printf("Select one of the following options:\n");
    printf("1. Recover deleted file\n");
    printf("2. Recover lost file\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter name of file to recover: ");
            scanf("%s", filename);

            fp = fopen(filename, "r");

            if(fp == NULL) {
                printf("Error opening file!\n");
                exit(1);
            }

            fseek(fp, 0, SEEK_END);
            size = ftell(fp);

            printf("Size of file: %d bytes\n", size);
            printf("File contents: ");

            fseek(fp, 0, SEEK_SET);
            while((ch = fgetc(fp)) != EOF) {
                printf("%c", ch);
            }

            fclose(fp);
            break;

        case 2:
            printf("Enter size of file to recover (in bytes): ");
            scanf("%d", &size);

            printf("Enter contents of file: ");
            scanf("%s", data);

            printf("Enter name of file to save: ");
            scanf("%s", filename);

            fp = fopen(filename, "w");

            if(fp == NULL) {
                printf("Error creating file!\n");
                exit(1);
            }

            for(i = 0; i < size; i++) {
                fputc(data[i], fp);
            }

            fclose(fp);
            printf("File saved!\n");
            break;

        default:
            printf("Invalid choice!\n");
            break;
    }

    return 0;
}