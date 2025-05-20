//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAXCHAR 1000

int main()
{
    char str[MAXCHAR], filename[MAXCHAR];
    FILE *fp;
    printf("Enter filename to watermark: ");
    scanf("%s", filename);
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(EXIT_FAILURE);
    }
    printf("Enter watermark text: ");
    scanf(" %[^\n]s", str);
    srand(time(0));
    int rand_num = rand() % 1000 + 1;
    char rand_str[10];
    sprintf(rand_str, "%d", rand_num);
    strcat(str, " ");
    strcat(str, rand_str);
    char watermark[MAXCHAR];
    strcpy(watermark, "<<");
    strcat(watermark, str);
    strcat(watermark, ">>");
    char temp[MAXCHAR];
    strcpy(temp, filename);
    char *ext;
    ext = strchr(temp, '.');
    char new_filename[MAXCHAR];
    strncpy(new_filename, filename, strlen(filename) - strlen(ext));
    strcat(new_filename, "_watermarked");
    strcat(new_filename, ext);
    FILE *fp2;
    fp2 = fopen(new_filename, "w");
    if (fp2 == NULL) {
        printf("Error creating watermarked file\n");
        exit(EXIT_FAILURE);
    }
    fprintf(fp2, "%s\n", watermark);
    while (fgets(str, MAXCHAR, fp) != NULL) {
        fprintf(fp2, "%s", str);
    }
    fclose(fp);
    fclose(fp2);
    printf("Success! Watermarked file saved as %s\n", new_filename);
    return 0;
}