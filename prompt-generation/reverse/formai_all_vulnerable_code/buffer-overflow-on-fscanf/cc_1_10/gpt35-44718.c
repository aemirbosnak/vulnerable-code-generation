//FormAI DATASET v1.0 Category: System process viewer ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

void colorfulPrinting(char *str){
    printf("\033[1;32m");
    printf("%s", str);
    printf("\033[0m");
}

int main(){
    DIR *d;
    struct dirent *dir;
    char path[1024], buffer[1024], name[32];
    int pid;
    FILE *fp;

    d = opendir("/proc");
    if(d){
        while((dir = readdir(d)) != NULL){
            if(!strcmp(dir->d_name, ".") || !strcmp(dir->d_name, ".."))
                continue;
            if(!isdigit(*dir->d_name))
                continue;

            pid = atoi(dir->d_name);
            sprintf(path, "/proc/%d/cmdline", pid);

            fp = fopen(path, "r");
            
            if(fp){
                fscanf(fp, "%s", buffer);

                sprintf(name, "[%s]", buffer);

                printf("%d\t", pid);

                if(strstr(name, "sleep")){
                    colorfulPrinting(name);
                    printf("\n");
                } else if(strstr(name, "ls")){
                    printf("\033[1m%s\033[0m\n", name);
                } else {
                    printf("%s\n", name);
                }

                fclose(fp);
            }
        }
        closedir(d);
    }
    return 0;
}