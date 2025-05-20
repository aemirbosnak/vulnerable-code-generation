//FormAI DATASET v1.0 Category: System process viewer ; Style: surprised
#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<string.h>

int main(void){
    DIR* proc_folder = opendir("/proc"); //Opening the /proc folder
    struct dirent* proc_entry; //A reference to a file in the folder
    
    if(proc_folder == NULL){
        printf("Error opening /proc folder\n");
        return 1; //Exiting the program if there is an error reading the proc folder
    }
    printf("PID      Process Name      Status      Memory Usage\n");
    printf("--------------------------------------------------\n");
    while((proc_entry = readdir(proc_folder)) != NULL){ //Looping through each file in the proc_folder
        if(proc_entry->d_type == DT_DIR){ //Checking if it is a directory
            int is_digit = 1; //A flag indicating if the directory name consists of digits only
            for(int i=0; i<strlen(proc_entry->d_name); i++){ //Looping through each character in the directory name
                if(!isdigit(proc_entry->d_name[i])){ //Checking if the character is not a digit
                    is_digit = 0;
                    break;
                }
            }
            if(is_digit){ //Checking if the directory name consists of digits only
                char status_file_path[100] = "/proc/"; //Creating the file path for the status file
                strcat(status_file_path, proc_entry->d_name);
                strcat(status_file_path, "/status");
                
                FILE* status_file = fopen(status_file_path, "r"); //Opening the status file
                if(status_file == NULL){ //Checking if there is an error opening the status file
                    printf("Error opening %s\n", status_file_path);
                }
                else{
                    char line[200]; //A buffer for each line in the file
                    char pid[10] = ""; //A buffer for the pid of the process
                    char name[100] = ""; //A buffer for the name of the process
                    char status[50] = ""; //A buffer for the status of the process
                    unsigned long vm_size = 0; //A buffer for the virtual memory usage of the process
                    
                    while(fgets(line, sizeof(line), status_file) != NULL){ //Looping through each line in the file
                        if(sscanf(line, "Pid: %[0-9]", pid) == 1){ //Scanning for the pid of the process
                            continue; //Skipping to the next line
                        }
                        if(sscanf(line, "Name: %[^\n]", name) == 1){ //Scanning for the name of the process
                            continue; //Skipping to the next line
                        }
                        if(sscanf(line, "VmSize: %lu", &vm_size) == 1){ //Scanning for the virtual memory usage of the process
                            break; //Exiting the loop as we have all the data we need
                        }
                        if(sscanf(line, "State: %[^\n]", status) == 1){ //Scanning for the status of the process
                            continue; //Skipping to the next line
                        }
                    }
                    printf("%-8s%-19s%-12s%lu\n", pid, name, status, vm_size/1024); //Printing the process data
                    fclose(status_file); //Closing the status file
                }
            }
        }
    }
    closedir(proc_folder); //Closing the proc folder
    return 0;
}