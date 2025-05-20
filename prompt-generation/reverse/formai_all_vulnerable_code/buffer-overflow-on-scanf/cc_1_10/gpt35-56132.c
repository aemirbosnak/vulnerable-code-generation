//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: brave
#include <stdio.h>
#include <string.h>

int main() {
    char fileName[100];
    int i, j, p, signature;
    FILE *fp;

    printf("Enter file name to scan: ");
    scanf("%s", fileName);

    fp = fopen(fileName, "rb");

    if(fp == NULL) {
        printf("Error: Unable to open file.\n");
        return 0;
    }

    printf("Scanning file for virus signatures...\n");

    fseek(fp,0L,SEEK_END);
    p = ftell(fp);
    rewind(fp);

    for(i=0;i<=p;i++){
        signature=0;

        if(fgetc(fp) == 'C'){
            signature++;

            if(fgetc(fp) == 'A'){
                signature++;

                if(fgetc(fp) == 'N'){
                    signature++;

                    if(fgetc(fp) == 'A'){
                        signature++;

                        if(fgetc(fp) == 'N'){
                            signature++;

                            if(fgetc(fp) == 'T'){
                                signature++;
                            }
                        }
                    }
                }
            }
        }
        if(signature==6){
            printf("Virus Signature Found!\n");
            fclose(fp);
            return 0;
        }
    }
    
    printf("Clean File.\n");
    fclose(fp);
    return 0;
}