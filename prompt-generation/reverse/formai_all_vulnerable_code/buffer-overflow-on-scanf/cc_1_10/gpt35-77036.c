//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LEN 256

void scan_file(char* filename);

int main(int argc, char* argv[]) {
    char filename[MAX_FILENAME_LEN];

    printf("Enter filename to scan: ");
    scanf("%s", filename);

    scan_file(filename);

    return 0;
}

void scan_file(char* filename) {
    FILE *fp;
    char ch;
    int virus_detected = 0;

    if((fp=fopen(filename,"r"))==NULL) {
        printf("Error: File not found.\n");
        return;
    }

    while((ch=getc(fp))!=EOF) {
        // check for virus patterns
        if(ch == 'v' || ch == 'V') {
            // check next 3 characters
            char buffer[4];
            buffer[0] = ch;
            for(int i=1; i < 4; i++) {
                buffer[i] = getc(fp);
            }

            // compare buffer with known virus patterns
            if(strcmp(buffer, "v1ru") == 0 || strcmp(buffer, "V1RU") == 0) {
                printf("Virus pattern found! Please remove file immediately.\n");
                virus_detected = 1;
                break;
            }
        }
    }

    fclose(fp);

    if(!virus_detected) {
        printf("No virus found. File is safe to use.\n");
    }
}