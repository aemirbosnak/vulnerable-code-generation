//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

void scanDir(char *dirName){
    struct dirent *direntPtr;
    DIR *dirPtr;
    dirPtr = opendir(dirName);
    if (dirPtr == NULL){
        printf("Error opening directory %s\n", dirName);
        return;
    }
    while ((direntPtr = readdir(dirPtr)) != NULL){
        char filePath[1024];
        strcpy(filePath, dirName);
        strcat(filePath, "/");
        strcat(filePath, direntPtr->d_name);
        if (strcmp(direntPtr->d_name, ".") == 0 || strcmp(direntPtr->d_name, "..") == 0){
            continue;
        }
        if (direntPtr->d_type == DT_DIR){
            scanDir(filePath);
        }
        else if(direntPtr->d_type == DT_REG){
            char *extension = strrchr(direntPtr->d_name, '.');
            if (extension != NULL && strcmp(extension, ".exe") == 0){
                FILE *filePtr = fopen(filePath, "r");
                if (filePtr == NULL){
                    printf("Error opening file %s\n", filePath);
                    continue;
                }
                char buffer[4096];
                size_t bytesRead;
                while (!feof(filePtr)){
                    bytesRead = fread(buffer, 1, sizeof(buffer), filePtr);
                    for (int i = 0; i < bytesRead; i++){
                        if (buffer[i] == 'v' && buffer[i+1] == 'i' && buffer[i+2] == 'r' && buffer[i+3] == 'u' && buffer[i+4] == 's'){
                            printf("Virus detected in file %s\n", filePath);
                            break;
                        }
                    }
                }
                fclose(filePtr);
            }
        }
    }
    closedir(dirPtr);
}

int main(){
    char dirName[1024];
    printf("Enter directory to scan: ");
    gets(dirName);
    scanDir(dirName);
    printf("Scan complete!\n");
    return 0;
}