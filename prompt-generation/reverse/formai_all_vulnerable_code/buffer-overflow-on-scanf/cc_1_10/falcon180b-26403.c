//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int i, j, k, m, n, p, q, temp, sum;
    char ch;
    FILE *fp;
    char filename[20];
    printf("Enter the name of the file to be encrypted: ");
    scanf("%s",filename);
    fp = fopen(filename,"r");
    if(fp == NULL) {
        printf("File not found!");
        exit(0);
    }
    printf("Enter the number of rounds for encryption: ");
    scanf("%d",&n);
    printf("Enter the key: ");
    for(i=0;i<n;i++) {
        scanf("%d",&k);
        k = k%256;
    }
    rewind(fp);
    printf("Enter the name of the output file: ");
    scanf("%s",filename);
    fp = fopen(filename,"w");
    if(fp == NULL) {
        printf("File could not be created!");
        exit(0);
    }
    while((ch = fgetc(fp))!= EOF) {
        sum = 0;
        for(i=0;i<n;i++) {
            sum += k;
            k = k%256;
        }
        for(i=0;i<n;i++) {
            m = (ch + sum)%256;
            if(m < 32 || m > 126) {
                if(m < 32) {
                    m = m + 128;
                } else {
                    m = m - 128;
                }
            }
            p = m + (i*32);
            q = p%256;
            temp = p;
            p = q;
            q = temp;
            q = q%256;
            fprintf(fp,"%c",q);
        }
    }
    fclose(fp);
    printf("File encrypted successfully!");
    return 0;
}