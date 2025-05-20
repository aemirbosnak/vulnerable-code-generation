//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: decentralized
// C Antivirus scanner program 
// decentralized style
// by [Your Name]

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

#define MAX_PATH_LENGTH 256
#define MAX_LINE_LENGTH 1024

char *virus_patterns[] = {"Ransomware", "Trojan", "Adware", "Keylogger", "Worm", "Spyware"};
int num_virus_patterns = sizeof(virus_patterns) / sizeof(virus_patterns[0]);

int scan_directory(const char *path);
int scan_file(const char *filepath);

int main(int argc, char **argv) {
    char path[MAX_PATH_LENGTH];
    printf("Enter directory path to scan: ");
    scanf("%s", path);
    printf("Scanning directory: %s\n", path);
    int num_infected = scan_directory(path);
    printf("Scan complete. %d infected file(s) found.\n", num_infected);
    return 0;
}

int scan_directory(const char *path) {
    DIR *dir;
    struct dirent *entry;
    int count = 0;

    if ((dir = opendir(path)) == NULL) {
        printf("Unable to open directory: %s\n", path);
        return 0;
    }

    while ((entry = readdir(dir)) != NULL) {
        char filepath[MAX_PATH_LENGTH];
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        snprintf(filepath, MAX_PATH_LENGTH, "%s/%s", path, entry->d_name);

        if (entry->d_type == DT_DIR) {
            count += scan_directory(filepath);
        } else if (entry->d_type == DT_REG) {
            count += scan_file(filepath);
        }
    }

    closedir(dir);
    return count;
}

int scan_file(const char *filepath) {
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    int count = 0;

    if ((fp = fopen(filepath, "r")) == NULL) {
        printf("Unable to open file: %s\n", filepath);
        return 0;
    }

    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        for (int i = 0; i < num_virus_patterns; i++) {
            if (strstr(line, virus_patterns[i]) != NULL) {
                printf("File infected: %s\n", filepath);
                count++;
                break;
            }
        }
    }

    fclose(fp);
    return count;
}