//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n, i, j, k, l, m, o, p, q, r, s, t, u, v, w, x, y, z;
    int a, b, c, d, e, f, g, h;
    int A[26], B[26], C[26], D[26], E[26], F[26], G[26], H[26];
    int X[26], Y[26], Z[26];
    int num = 0;
    int count = 0;
    int flag = 0;
    int temp;
    int sum;
    int max_sum = 0;
    int max_ending_here = 0;
    int start = 0;
    int end = 0;
    int max_len = 0;
    int len = 0;
    int pos = 0;
    int max_pos = 0;
    FILE *fp;
    char ch;
    char filename[20];
    char line[100];
    srand(time(NULL));
    printf("Enter the length of the string: ");
    scanf("%d", &n);
    printf("Enter the string: ");
    scanf("%s", line);
    for(i=0; i<n; i++) {
        A[line[i]]++;
    }
    printf("\nThe frequency of each character in the string is:\n");
    for(i='a'; i<='z'; i++) {
        printf("%c %d\n", i, A[i]);
    }
    printf("\nEnter the number of strings to be generated: ");
    scanf("%d", &num);
    printf("\nThe %d strings are:\n", num);
    for(i=0; i<num; i++) {
        printf("String %d: ", i+1);
        for(j=0; j<n; j++) {
            printf("%c", line[j]);
        }
        printf("\n");
    }
    printf("\nEnter the file name: ");
    scanf("%s", filename);
    fp = fopen(filename, "w");
    if(fp == NULL) {
        printf("\nUnable to open file");
        exit(0);
    }
    for(i=0; i<n; i++) {
        fprintf(fp, "%c %d\n", line[i], A[line[i]]);
    }
    fclose(fp);
    printf("\nThe file has been created successfully");
    return 0;
}