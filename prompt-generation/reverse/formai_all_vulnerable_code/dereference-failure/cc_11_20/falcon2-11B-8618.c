//Falcon2-11B DATASET v1.0 Category: File Synchronizer ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *fp1, *fp2, *fp3;
    char str[100];

    /* create two files */
    if ((fp1 = fopen("file1.txt", "w")) == NULL) {
        fprintf(stderr, "Error opening file1.txt\n");
        exit(1);
    }
    if ((fp2 = fopen("file2.txt", "w")) == NULL) {
        fprintf(stderr, "Error opening file2.txt\n");
        exit(1);
    }

    /* write some data to them */
    printf("Enter some text to write to file1.txt: ");
    fgets(str, sizeof(str), stdin);
    fprintf(fp1, "%s", str);
    printf("Text written to file1.txt\n");
    fflush(stdout);

    printf("Enter some text to write to file2.txt: ");
    fgets(str, sizeof(str), stdin);
    fprintf(fp2, "%s", str);
    printf("Text written to file2.txt\n");
    fflush(stdout);

    /* copy file1.txt to file2.txt */
    if ((fp3 = fopen("file1.txt", "r")) == NULL) {
        fprintf(stderr, "Error opening file1.txt\n");
        exit(1);
    }
    if ((fp2 = fopen("file2.txt", "w")) == NULL) {
        fprintf(stderr, "Error opening file2.txt\n");
        exit(1);
    }
    if (fread(str, sizeof(char), 1, fp3) == 1) {
        fwrite(str, sizeof(char), 1, fp2);
    }
    fclose(fp3);
    fclose(fp2);
    printf("file1.txt copied to file2.txt\n");
    fflush(stdout);

    /* compare the two files */
    if ((fp1 = fopen("file1.txt", "r")) == NULL) {
        fprintf(stderr, "Error opening file1.txt\n");
        exit(1);
    }
    if ((fp2 = fopen("file2.txt", "r")) == NULL) {
        fprintf(stderr, "Error opening file2.txt\n");
        exit(1);
    }
    if (fread(str, sizeof(char), 1, fp1)!= 1 || fread(str, sizeof(char), 1, fp2)!= 1) {
        fprintf(stderr, "Error reading files\n");
        exit(1);
    }
    if (strcmp(str, "\0") == 0) {
        printf("The two files are identical\n");
    } else {
        printf("The two files are not identical\n");
    }
    fclose(fp1);
    fclose(fp2);
    printf("files compared\n");
    fflush(stdout);

    /* close and delete the files */
    if (remove("file1.txt")!= 0) {
        fprintf(stderr, "Error deleting file1.txt\n");
        exit(1);
    }
    if (remove("file2.txt")!= 0) {
        fprintf(stderr, "Error deleting file2.txt\n");
        exit(1);
    }
    printf("files deleted\n");
    fflush(stdout);

    return 0;
}