//GPT-4o-mini DATASET v1.0 Category: Intrusion detection system ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <openssl/md5.h>
#include <unistd.h>

#define BASELINE_FILE "baseline.txt"
#define LOG_FILE "log.txt"
#define MAX_PATH 1024

void compute_md5(const char *filename, unsigned char *result) {
    MD5_CTX ctx;
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("File opening failed");
        return;
    }
    
    MD5_Init(&ctx);
    unsigned char data[1024];
    size_t bytes;
    
    while ((bytes = fread(data, 1, sizeof(data), file)) != 0) {
        MD5_Update(&ctx, data, bytes);
    }
    
    MD5_Final(result, &ctx);
    fclose(file);
}

void log_change(const char *filename) {
    FILE *log = fopen(LOG_FILE, "a");
    if (log == NULL) {
        perror("Failed to open log file");
        return;
    }
    fprintf(log, "Change detected in file: %s\n", filename);
    fclose(log);
}

int compare_files(const char *filename, unsigned char *old_hash) {
    unsigned char new_hash[MD5_DIGEST_LENGTH];
    compute_md5(filename, new_hash);
    
    return memcmp(old_hash, new_hash, MD5_DIGEST_LENGTH) != 0;
}

void build_baseline(const char *directory) {
    FILE *baseline = fopen(BASELINE_FILE, "w");
    if (baseline == NULL) {
        perror("Failed to open baseline file");
        return;
    }
    
    struct dirent *entry;
    DIR *dp = opendir(directory);
    if (dp == NULL) {
        perror("Unable to open directory");
        fclose(baseline);
        return;
    }
    
    while ((entry = readdir(dp))) {
        if (entry->d_type == DT_REG) { // Regular file
            char filepath[MAX_PATH];
            snprintf(filepath, sizeof(filepath), "%s/%s", directory, entry->d_name);
            unsigned char hash[MD5_DIGEST_LENGTH];
            compute_md5(filepath, hash);
            fprintf(baseline, "%s ", entry->d_name);
            for (int i = 0; i < MD5_DIGEST_LENGTH; i++) {
                fprintf(baseline, "%02x", hash[i]);
            }
            fprintf(baseline, "\n");
        }
    }
    closedir(dp);
    fclose(baseline);
}

void monitor_directory(const char *directory) {
    FILE *baseline = fopen(BASELINE_FILE, "r");
    if (baseline == NULL) {
        perror("No baseline found, building one");
        build_baseline(directory);
        return;
    }
    
    char filename[MAX_PATH];
    unsigned char old_hash[MD5_DIGEST_LENGTH];
    
    while (fscanf(baseline, "%s", filename) != EOF) {
        fscanf(baseline, "%s", (char *)old_hash);
        
        char path[MAX_PATH];
        snprintf(path, sizeof(path), "%s/%s", directory, filename);
        
        if (access(path, F_OK) == -1) {
            log_change(filename);
        } else {
            if (compare_files(path, old_hash)) {
                log_change(filename);
            }
        }
    }
    fclose(baseline);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory to monitor>\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    const char *directory = argv[1];
    
    while (1) {
        monitor_directory(directory);
        sleep(10); // Monitor every 10 seconds
    }
    
    return EXIT_SUCCESS;
}