//Gemma-7B DATASET v1.0 Category: Intrusion detection system ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>

#define LOG_FILE "intrusion_log.txt"

int main()
{
    char filename[256];
    char buffer[4096];
    FILE *log_file;
    int i, j, file_size;

    // Open the log file
    log_file = fopen(LOG_FILE, "a");

    // Monitor the file system for changes
    while (1)
    {
        system("inotifywait -m");

        // Get the filename of the changed file
        scanf("%s", filename);

        // Check if the file is a regular file
        if (stat(filename, NULL) & S_IFREG)
        {
            // Read the file contents
            FILE *file = fopen(filename, "r");
            file_size = fread(buffer, 1, 4096, file);
            fclose(file);

            // Check if the file contents have changed
            for (i = 0; i < file_size; i++)
            {
                for (j = 0; j < file_size; j++)
                {
                    if (buffer[i] != buffer[j])
                    {
                        // Log the intrusion
                        fprintf(log_file, "Intrusion detected: File %s changed at %s\n", filename, time(NULL));

                        // Take other actions, such as sending an email alert or logging the user's IP address
                        break;
                    }
                }
            }
        }
    }

    fclose(log_file);
    return 0;
}