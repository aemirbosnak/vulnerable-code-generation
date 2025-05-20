//FormAI DATASET v1.0 Category: System boot optimizer ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>

void clear_buffer()
{
    // clear keyboard input buffer
    int c = 0;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

void optimize_boot()
{
    printf("Running C System Boot Optimizer...\n\n");

    int boot_time = 40; // default boot time in seconds
    char confirm = '\0'; // user confirmation

    // prompt user for desired boot time
    printf("Please enter your desired boot time (in seconds): ");
    scanf("%d", &boot_time);
    clear_buffer();

    // confirm user's choice
    printf("\nYour boot time will be set to %d seconds. Do you wish to proceed? (y/n): ", boot_time);
    scanf("%c", &confirm);
    clear_buffer();

    if (confirm == 'n')
    {
        printf("\nBoot optimization cancelled. Exiting program...\n");
        exit(0);
    }
    else if (confirm == 'y')
    {
        printf("\nProceeding with boot optimization...\n\n");
    }
    else
    {
        printf("\nInvalid input. Boot optimization cancelled. Exiting program...\n");
        exit(1);
    }

    // change boot time
    FILE *fp = fopen("/etc/systemd/system.conf", "r+");
    char buf[1024];
    int line_number = 0;
    int num_lines = 0;

    while (fgets(buf, sizeof(buf), fp) != NULL)
    {
        num_lines++;
        if (strstr(buf, "DefaultTimeoutStartSec") != NULL)
        {
            fseek(fp, -strlen(buf), SEEK_CUR);
            fprintf(fp, "DefaultTimeoutStartSec=%d\n", boot_time);
            printf("Boot time set to %d seconds.\n", boot_time);
        }
    }

    if (num_lines == line_number)
    {
        printf("Unable to change boot time. Please try again later.\n");
    }

    fclose(fp);

    // delete unnecessary startup applications
    printf("\nSearching for unnecessary startup applications...\n");

    DIR *dir;
    struct dirent *ent;
    bool found_app = false;

    char path[1024];
    char app_path[1024];

    dir = opendir("/etc/xdg/autostart");

    if (dir == NULL)
    {
        printf("Directory '/etc/xdg/autostart' not found.\n");
    }
    else
    {
        while ((ent = readdir(dir)) != NULL)
        {
            if (strstr(ent->d_name, ".desktop") != NULL)
            {
                memset(path, '\0', sizeof(path));
                memset(app_path, '\0', sizeof(app_path));
                strcat(path, "/etc/xdg/autostart/");
                strcat(app_path, ent->d_name);
                strcat(path, app_path);

                fp = fopen(path, "r");
                while (fgets(buf, sizeof(buf), fp) != NULL)
                {
                    if (strstr(buf, "X-GNOME-Autostart-enabled") != NULL)
                    {
                        if (strstr(buf, "true") != NULL)
                        {
                            printf("%s is enabled.\n", app_path);
                            found_app = true;
                        }
                        break;
                    }
                }
                fclose(fp);
            }
        }
        closedir(dir);
    }

    if (!found_app)
    {
        printf("No unnecessary startup applications found.\n");
    }
    else
    {
        printf("\nWould you like to disable these startup applications? (y/n): ");
        scanf("%c", &confirm);
        clear_buffer();

        if (confirm == 'n')
        {
            printf("\nStartup application disabling cancelled.\n");
        }
        else if (confirm == 'y')
        {
            printf("\nDisabling unnecessary startup applications...\n\n");
            
            dir = opendir("/etc/xdg/autostart");

            if (dir == NULL)
            {
                printf("Directory '/etc/xdg/autostart' not found.\n");
            }
            else
            {
                while ((ent = readdir(dir)) != NULL)
                {
                    if (strstr(ent->d_name, ".desktop") != NULL)
                    {
                        memset(path, '\0', sizeof(path));
                        memset(app_path, '\0', sizeof(app_path));
                        strcat(path, "/etc/xdg/autostart/");
                        strcat(app_path, ent->d_name);
                        strcat(path, app_path);

                        fp = fopen(path, "r+");
                        while (fgets(buf, sizeof(buf), fp) != NULL)
                        {
                            if (strstr(buf, "X-GNOME-Autostart-enabled") != NULL)
                            {
                                if (strstr(buf, "true") != NULL)
                                {
                                    fseek(fp, -strlen(buf), SEEK_CUR);
                                    fprintf(fp, "X-GNOME-Autostart-enabled=false\n");
                                    printf("%s has been disabled.\n", app_path);
                                }
                                break;
                            }
                        }
                        fclose(fp);
                    }
                }
                closedir(dir);
            }
        }
        else
        {
            printf("\nInvalid input. Startup application disabling cancelled.\n");
        }
    }

    printf("\nC System Boot Optimizer has finished running!\n");
}

int main()
{
    optimize_boot();
    return 0;
}