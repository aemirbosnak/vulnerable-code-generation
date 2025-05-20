//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int count = 0;
    while(1) {
        FILE *fp;
        char total_ram[128], free_ram[128], used_ram[128];
        fp = fopen("/proc/meminfo","r");
        if(fp == NULL) {
            printf("Error: Failed to open meminfo file.\n");
            exit(1);
        }
        for(int i=0;i<3;i++) {
            char temp[128];
            fscanf(fp, "%s %s %*s", temp, total_ram);
        }
        fscanf(fp, "%s %s %*s", total_ram, total_ram);
        for(int i=0;i<2;i++) {
            char temp[128];
            fscanf(fp, "%s %s %*s", temp, free_ram);
        }

        long long total_ram_in_kb = atoll(total_ram);
        long long free_ram_in_kb = atoll(free_ram);
        long long used_ram_in_kb = total_ram_in_kb - free_ram_in_kb;

        printf("\033c"); //clear screen
        
        int bar_length = 20;
        int used_ram_percentage = (int)(100*used_ram_in_kb/(double)total_ram_in_kb);
        int bar_fill = (int)(bar_length*used_ram_percentage/100.0);
        
        printf("***************************************\n");
        printf("*                                     *\n");
        printf("*           C RAM Monitor             *\n");
        printf("*                                     *\n");
        printf("***************************************\n\n");

        printf("Total RAM: %lldKB\n", total_ram_in_kb);
        printf("Free RAM: %lldKB\n", free_ram_in_kb);
        printf("Used RAM: %lldKB (%d%%)\n", used_ram_in_kb, used_ram_percentage);

        printf("[");
        for(int i=0;i<bar_fill;i++) {
            printf("\033[32m||\033[0m");
        }
        for(int i=0;i<bar_length-bar_fill;i++) {
            printf(" ");
        }
        printf("]\n\n");

        printf("Press Ctrl+C to exit...\n");
        fclose(fp);
        sleep(1);
        count++;
    }
    return 0;
}