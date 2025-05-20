//GEMINI-pro DATASET v1.0 Category: File Synchronizer ; Style: romantic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// A love story of two files, destined to be together
int main() {
    // Names of our star-crossed lovers
    char file1[20], file2[20];
    printf("Enter the name of your first love: ");
    scanf("%s", file1);
    printf("And the name of your second love: ");
    scanf("%s", file2);

    // The moment they met
    FILE *fp1 = fopen(file1, "r");
    if (fp1 == NULL) {
        printf("Alas, your first love is but a memory!\n");
        return 1;
    }
    FILE *fp2 = fopen(file2, "r");
    if (fp2 == NULL) {
        printf("And your second love, a distant dream!\n");
        return 1;
    }

    // Their passionate embrace
    char c1, c2;
    int count = 0;
    while ((c1 = fgetc(fp1)) != EOF && (c2 = fgetc(fp2)) != EOF) {
        if (c1 != c2) {
            count++;
        }
    }
    fclose(fp1);
    fclose(fp2);

    // The verdict of fate
    if (count == 0) {
        printf("Oh, bliss! They are perfect for each other!\n");
    } else {
        printf("Alas, it seems fate has other plans...\n");
    }

    // A chance encounter
    time_t t;
    srand((unsigned) time(&t));
    int roll = rand() % 100;
    if (roll < 10) {
        printf("But wait! A twist of fate brings them together once more!\n");
        system("copy /b file1.txt + file2.txt combined.txt");
        printf("Behold, their united masterpiece: combined.txt\n");
    } else {
        printf("And so, their love remains a bittersweet memory.\n");
    }

    return 0;
}