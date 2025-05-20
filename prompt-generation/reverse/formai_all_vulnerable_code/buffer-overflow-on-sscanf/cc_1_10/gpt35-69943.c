//FormAI DATASET v1.0 Category: Browser Plugin ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>

// Define the function to get the active tab URL
void get_active_tab_url(char *url) {
    FILE* fp;
    char path[1035];

    fp = popen("xprop -root _NET_ACTIVE_WINDOW | awk '{print $5}' | sed 's/,//'","r");

    if (fp == NULL) {
        printf("Failed to run command\n" );
        exit(1);
    }

    fgets(path, sizeof(path)-1, fp);

    // Convert hex value to decimal
    int window_id;
    sscanf(path, "0x%x", &window_id);

    // Use xprop to get the active URL
    sprintf(path, "xprop -id %d _NET_WM_NAME WM_CLASS WM_WINDOW_ROLE _NET_WM_PID _MOTIF_WM_HINTS | egrep -i -e '(wm_name|wm_class|wm_window_role|_NET_WM_PID|_MOTIF_WM_HINTS)'", window_id);

    fp = popen(path, "r");

    if (fp == NULL) {
        printf("Failed to run command\n" );
        exit(1);
    }

    bool found_url = false;
    char url_prefix[] = "\"http";

    while (fgets(path, sizeof(path)-1, fp) != NULL) {
        // Look for the line that contains the URL
        if (strstr(path, url_prefix) != NULL) {
            // Remove leading whitespace
            char* trimmed_url = path;
            while (*trimmed_url == ' ') {
                trimmed_url++;
            }
            // Remove trailing newline character
            trimmed_url[strcspn(trimmed_url, "\n")] = 0;

            // Copy the URL to the output argument and set flag indicating success
            strcpy(url, trimmed_url);
            found_url = true;
            break;
        }
    }

    if (!found_url) {
        // Unable to find active URL
        printf("Unable to find active URL\n");
    }

    // Close the file pointer
    pclose(fp);
}

int main() {
    // Define URL buffer and get the active tab URL
    char url[256] = "";
    get_active_tab_url(url);

    printf("Active URL: %s\n", url);

    return 0;
}