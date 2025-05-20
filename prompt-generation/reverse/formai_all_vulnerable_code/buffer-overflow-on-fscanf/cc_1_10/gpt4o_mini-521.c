//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

#define MAX_FILES 1024
#define MAX_VIRUS_SIG 256
#define INFO_FILE "virus_info.txt"
#define SCAN_DIRECTORY "./"

typedef struct {
    char name[256];
    char signature[MAX_VIRUS_SIG];
} Virus;

void load_viruses(Virus *viruses, int *count) {
    FILE *file = fopen(INFO_FILE, "r");
    if (!file) {
        fprintf(stderr, "Unable to open virus info file!\n");
        exit(EXIT_FAILURE);
    }

    *count = 0;
    while (fscanf(file, "%[^:]: %[^\n]\n", viruses[*count].name, viruses[*count].signature) != EOF) {
        (*count)++;
    }
    fclose(file);
}

int scan_file(const char *filepath, Virus *viruses, int virus_count) {
    FILE *file = fopen(filepath, "rb");
    if (!file) {
        perror("File open error");
        return 0;
    }

    fseek(file, 0, SEEK_END);
    long fsize = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *buffer = malloc(fsize);
    if (!buffer) {
        fclose(file);
        perror("Memory allocation error");
        return 0;
    }
    fread(buffer, 1, fsize, file);
    fclose(file);

    for (int i = 0; i < virus_count; i++) {
        if (strstr(buffer, viruses[i].signature) != NULL) {
            printf("ALERT: %s detected in %s\n", viruses[i].name, filepath);
            free(buffer);
            return 1;
        }
    }

    free(buffer);
    return 0;
}

void scan_directory(const char *dirpath, Virus *viruses, int virus_count) {
    struct dirent *entry;
    struct stat fileStat;

    DIR *dp = opendir(dirpath);
    if (dp == NULL) {
        perror("Directory open error");
        return;
    }

    while ((entry = readdir(dp))) {
        if (entry->d_type == DT_REG) { // Regular file
            char fullpath[512];
            snprintf(fullpath, sizeof(fullpath), "%s/%s", dirpath, entry->d_name);
            if (scan_file(fullpath, viruses, virus_count)) {
                printf("Quarantine needed for file: %s\n", fullpath);
            }
        } else if (entry->d_type == DT_DIR && strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            char sub_dir[512];
            snprintf(sub_dir, sizeof(sub_dir), "%s/%s", dirpath, entry->d_name);
            scan_directory(sub_dir, viruses, virus_count); // Recursive scan
        }
    }

    closedir(dp);
}

void start_scan() {
    Virus viruses[MAX_FILES];
    int virus_count = 0;
    
    load_viruses(viruses, &virus_count);
    printf("Initiating scan through the neon-lit corridors...\n");
    
    scan_directory(SCAN_DIRECTORY, viruses, virus_count);

    printf("Scan complete. Don't get caught by the digital specters!\n");
}

int main() {
    printf("Loading CyberVirus Scanner...\n");
    start_scan();
    return 0;
}