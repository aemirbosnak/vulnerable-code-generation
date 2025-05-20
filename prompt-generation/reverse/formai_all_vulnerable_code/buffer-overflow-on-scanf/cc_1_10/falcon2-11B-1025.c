//Falcon2-11B DATASET v1.0 Category: File Synchronizer ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare_files(char *fname1, char *fname2) {
    FILE *fp1, *fp2;
    int c;

    fp1 = fopen(fname1, "rb");
    fp2 = fopen(fname2, "rb");

    if (fp1 == NULL || fp2 == NULL) {
        printf("Error opening files\n");
        return 1;
    }

    while ((c = getc(fp1))!= EOF) {
        if (c!= getc(fp2)) {
            printf("Files are not identical\n");
            fclose(fp1);
            fclose(fp2);
            return 1;
        }
    }

    fclose(fp1);
    fclose(fp2);
    return 0;
}

int update_file(char *fname1, char *fname2) {
    FILE *fp1, *fp2;
    int c;

    fp1 = fopen(fname1, "rb");
    fp2 = fopen(fname2, "wb");

    if (fp1 == NULL || fp2 == NULL) {
        printf("Error opening files\n");
        return 1;
    }

    while ((c = getc(fp1))!= EOF) {
        putc(c, fp2);
    }

    fclose(fp1);
    fclose(fp2);
    return 0;
}

int main() {
    char fname1[50], fname2[50];

    printf("Enter the name of the first file: ");
    scanf("%s", fname1);

    printf("Enter the name of the second file: ");
    scanf("%s", fname2);

    if (compare_files(fname1, fname2)) {
        printf("Files are identical.\n");
    } else {
        update_file(fname1, fname2);
        printf("Second file has been updated.\n");
    }

    return 0;
}