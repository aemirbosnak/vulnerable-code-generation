//GEMINI-pro DATASET v1.0 Category: Website Uptime Monitor ; Style: mind-bending
// Dive into the depths of web surveillance with this mind-bending C website uptime monitor!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <curl/curl.h>

// A peculiar struct to hold our cosmic insights
typedef struct {
    char *url;
    time_t last_checked;
    int status_code;
} WebMonitor;

// A cryptic function to probe the ethereal realm of the web
CURLcode etherealProbe(WebMonitor *monitor) {
    CURL *handle;
    CURLcode result;
    long code;

    handle = curl_easy_init();
    if (!handle) {
        return CURLE_FAILED_INIT;
    }

    curl_easy_setopt(handle, CURLOPT_URL, monitor->url);
    curl_easy_setopt(handle, CURLOPT_TIMEOUT, 5);
    curl_easy_setopt(handle, CURLOPT_FOLLOWLOCATION, 1);

    result = curl_easy_perform(handle);
    if (result != CURLE_OK) {
        return result;
    }

    curl_easy_getinfo(handle, CURLINFO_RESPONSE_CODE, &code);
    monitor->status_code = (int)code;

    curl_easy_cleanup(handle);
    return result;
}

// A mesmerizing function to unveil the secrets of time
time_t cosmicTime() {
    time_t rawtime;
    time(&rawtime);
    return rawtime;
}

// A kaleidoscopic function to paint the canvas of our celestial tapestry
void celestialCanvas(WebMonitor *monitors, int num_monitors) {
    int i;
    
    printf("****************************** &\n");
    printf("**        WEB UPTIME MONITOR    **\n");
    printf("****************************** &\n");
    printf("Website Url | Status Code | Last Checked\n");
    printf("----------------------------------------\n");
    for (i = 0; i < num_monitors; i++) {
        printf("%-20s | %3d | %ld\n", monitors[i].url, monitors[i].status_code, monitors[i].last_checked);
    }
    printf("----------------------------------------\n");
    printf("* = Your monitor is running. Enjoy! *\n");
    printf("**************************************\n");
}

int main() {
    // A celestial array of websites to monitor
    WebMonitor monitors[] = {
        {"https://www.google.com", 0, 0},
        {"https://www.facebook.com", 0, 0},
        {"https://www.amazon.com", 0, 0}
    };
    
    int num_monitors = sizeof(monitors) / sizeof(WebMonitor);

    // An infinite loop to traverse the fabric of time and space
    while (1) {
        int i;
        
        // Update the cosmic time
        time_t now = cosmicTime();

        // Probe the ethereal realms of the web
        for (i = 0; i < num_monitors; i++) {
            if (now - monitors[i].last_checked > 60) {
                CURLcode result = etherealProbe(&monitors[i]);
                if (result != CURLE_OK) {
                    printf("Error probing URL: %s\n", monitors[i].url);
                }
                monitors[i].last_checked = now;
            }
        }

        // Paint the celestial tapestry
        celestialCanvas(monitors, num_monitors);
        
        // Sleep for a moment to avoid overwhelming the cosmic fabric
        sleep(1);
    }

    return 0;
}