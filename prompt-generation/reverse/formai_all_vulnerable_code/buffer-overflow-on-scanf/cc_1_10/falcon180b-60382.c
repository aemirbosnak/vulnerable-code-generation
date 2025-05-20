//Falcon-180B DATASET v1.0 Category: System administration ; Style: introspective
#include <stdio.h>

int main() {
    int choice;
    char file_name[50];
    FILE *fp;
    int i, j;

    printf("Enter the file name: ");
    scanf("%s", file_name);

    printf("Enter 1 to read the file\n");
    printf("Enter 2 to write in the file\n");
    printf("Enter 3 to append in the file\n");

    scanf("%d", &choice);

    switch(choice) {
        case 1:
            fp = fopen(file_name, "r");
            if (fp == NULL) {
                printf("File not found\n");
            } else {
                printf("File contents:\n");
                while ((fgetc(fp))!= EOF) {
                    printf("%c", fgetc(fp));
                }
                fclose(fp);
            }
            break;
        case 2:
            fp = fopen(file_name, "w");
            if (fp == NULL) {
                printf("File not found\n");
            } else {
                printf("Enter the string to be written in the file: ");
                scanf("%s", &file_name);
                fprintf(fp, "%s", file_name);
                fclose(fp);
            }
            break;
        case 3:
            fp = fopen(file_name, "a");
            if (fp == NULL) {
                printf("File not found\n");
            } else {
                printf("Enter the string to be appended in the file: ");
                scanf("%s", &file_name);
                fprintf(fp, "%s", file_name);
                fclose(fp);
            }
            break;
        default:
            printf("Invalid choice\n");
    }

    return 0;
}