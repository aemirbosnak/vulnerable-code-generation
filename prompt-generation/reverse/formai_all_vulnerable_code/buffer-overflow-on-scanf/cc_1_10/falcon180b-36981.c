//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: multivariable
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<time.h>
#include<ctype.h>
#include<limits.h>
#include<stdbool.h>
#include<assert.h>

//Function to generate random string
void generateRandomString(char *str, int len) {
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    for(int i=0; i<len; i++) {
        str[i] = charset[rand() % strlen(charset)];
    }
    str[len] = '\0';
}

//Function to add watermark
void addWatermark(FILE *fp, char *watermark) {
    rewind(fp);
    char ch;
    while((ch = fgetc(fp))!= EOF) {
        if(isalpha(ch)) {
            fprintf(fp, "%c%c", ch, watermark[0]);
        } else {
            fprintf(fp, "%c", ch);
        }
    }
}

//Function to remove watermark
void removeWatermark(FILE *fp, char *watermark) {
    rewind(fp);
    char ch;
    while((ch = fgetc(fp))!= EOF) {
        if(isalpha(ch)) {
            if(tolower(ch) == tolower(watermark[0])) {
                fprintf(fp, "%c", watermark[1]);
            } else {
                fprintf(fp, "%c", ch);
            }
        } else {
            fprintf(fp, "%c", ch);
        }
    }
}

//Function to check if watermark is present
bool isWatermarkPresent(FILE *fp, char *watermark) {
    rewind(fp);
    char ch;
    while((ch = fgetc(fp))!= EOF) {
        if(isalpha(ch)) {
            if(tolower(ch) == tolower(watermark[0])) {
                if(tolower(fgetc(fp)) == tolower(watermark[1])) {
                    return true;
                }
            }
        }
    }
    return false;
}

int main() {
    char filename[100];
    printf("Enter filename: ");
    scanf("%s", filename);

    FILE *fp = fopen(filename, "r+");
    if(fp == NULL) {
        printf("Error opening file\n");
        exit(0);
    }

    char watermark[100];
    generateRandomString(watermark, 2);

    addWatermark(fp, watermark);
    printf("Watermark added\n");

    removeWatermark(fp, watermark);
    printf("Watermark removed\n");

    if(isWatermarkPresent(fp, watermark)) {
        printf("Watermark is present\n");
    } else {
        printf("Watermark is not present\n");
    }

    fclose(fp);
    return 0;
}