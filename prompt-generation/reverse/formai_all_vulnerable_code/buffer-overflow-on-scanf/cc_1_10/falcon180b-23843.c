//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char *name;
    char *signature;
    int length;
} virus;

int main() {
    char file_name[100];
    char ch;
    FILE *fp;
    virus v[] = {{"Cavity.A", "CAVITY", 80}, {"Cavity.B", "CABITY", 80}, {"Cavity.C", "CBITY", 80}, {"Cavity.D", "CCITY", 80}, {"Cavity.E", "CDITY", 80}, {"Cavity.F", "CEITY", 80}, {"Cavity.G", "CFITY", 80}};
    int n = sizeof(v)/sizeof(v[0]);
    int i, j, k, flag = 0;

    printf("Enter the name of the file to be scanned: ");
    scanf("%s", file_name);

    fp = fopen(file_name, "rb");

    if(fp == NULL) {
        printf("File not found or cannot be opened.\n");
        exit(0);
    }

    char *buffer = malloc(80*sizeof(char));

    while(fread(buffer, sizeof(char), 80, fp)!= 0) {
        for(i=0; i<n; i++) {
            for(j=0; j<strlen(v[i].signature); j++) {
                if(tolower(buffer[j])!= tolower(v[i].signature[j])) {
                    break;
                }
            }
            if(j == strlen(v[i].signature)) {
                flag = 1;
                printf("\n%s virus found in %s\n", v[i].name, file_name);
            }
        }
        if(flag == 1) {
            break;
        }
    }

    if(flag == 0) {
        printf("\nNo virus found in %s\n", file_name);
    }

    fclose(fp);
    free(buffer);
    return 0;
}