//FormAI DATASET v1.0 Category: System process viewer ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>

int main() {
    DIR *d;
    struct dirent *dir;
    int i = 0;

    printf("Welcome to the process viewer!\n\n");

    while(1) {
        d = opendir("/proc");
        if(d) {
            printf("PID\tName\tState\tUser\n");
            while((dir = readdir(d)) != NULL) {
                char path[100], line[100], name[100], state, user[100];
                FILE *fp;

                if(!strcmp(dir->d_name, ".") || !strcmp(dir->d_name, ".."))
                    continue;
                
                if(!isdigit(dir->d_name[0]))
                    continue;

                strcpy(path, "/proc/");
                strcat(path, dir->d_name);
                strcat(path, "/status");

                fp = fopen(path, "r");
                if(fp) {
                    while(fgets(line, 100, fp)) {
                        sscanf(line, "%s %c", name, &state);
                        if(!strcmp(name, "State:")) {
                            if(state == 'R' || state == 'S')
                                printf("%s\t%c\t", dir->d_name, state);
                            break;
                        }
                    }
                    fclose(fp);
                }

                strcpy(path, "/proc/");
                strcat(path, dir->d_name);
                strcat(path, "/loginuid");

                fp = fopen(path, "r");
                if(fp) {
                    while(fgets(line, 100, fp)) {
                        sscanf(line, "%s", user);
                        break;
                    }
                    fclose(fp);
                }

                if(user[0]) {
                    printf("%s\n", user);
                    i++;
                }
            }
            printf("\nTotal number of active processes: %d\n\n", i);
            closedir(d);
        }
        sleep(2);
        system("clear");
    }

    return 0;
}