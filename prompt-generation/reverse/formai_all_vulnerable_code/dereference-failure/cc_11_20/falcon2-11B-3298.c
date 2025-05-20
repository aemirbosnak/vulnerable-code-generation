//Falcon2-11B DATASET v1.0 Category: Antivirus scanner ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    if (argc!= 2)
    {
        fprintf(stderr, "Usage: %s <path_to_scan>\n", argv[0]);
        return 1;
    }
    
    char *path = argv[1];
    struct stat st;
    int fd;
    int scan_flag = 0;
    
    if (stat(path, &st) == -1)
    {
        fprintf(stderr, "Error: %s does not exist.\n", path);
        return 1;
    }
    
    if (S_ISDIR(st.st_mode))
    {
        fd = open(path, O_RDONLY);
        if (fd == -1)
        {
            fprintf(stderr, "Error: Cannot open %s.\n", path);
            return 1;
        }
        
        DIR *dir = opendir(path);
        if (dir == NULL)
        {
            fprintf(stderr, "Error: Cannot open directory %s.\n", path);
            return 1;
        }
        
        struct dirent *entry;
        while ((entry = readdir(dir))!= NULL)
        {
            if (entry->d_type == DT_REG)
            {
                if (scan_flag)
                {
                    continue;
                }
                
                char *file_name = entry->d_name;
                if (stat(file_name, &st) == -1)
                {
                    fprintf(stderr, "Error: Cannot stat %s.\n", file_name);
                    return 1;
                }
                
                if (S_ISREG(st.st_mode))
                {
                    scan_flag = 1;
                    
                    char *buffer = malloc(4096);
                    if (buffer == NULL)
                    {
                        fprintf(stderr, "Error: Out of memory.\n");
                        return 1;
                    }
                    
                    int read_size = 0;
                    int write_size = 0;
                    while ((read_size = read(fd, buffer, 4096)) > 0)
                    {
                        if (write_size == 0)
                        {
                            write_size = read_size;
                        }
                        else
                        {
                            if (write_size < read_size)
                            {
                                write_size = read_size;
                            }
                        }
                        
                        write_size += write(1, buffer, read_size);
                    }
                    
                    if (write_size!= read_size)
                    {
                        fprintf(stderr, "Error: File size mismatch.\n");
                        return 1;
                    }
                    
                    free(buffer);
                }
            }
        }
        
        closedir(dir);
    }
    
    if (close(fd) == -1)
    {
        fprintf(stderr, "Error: Cannot close %s.\n", path);
        return 1;
    }
    
    return 0;
}