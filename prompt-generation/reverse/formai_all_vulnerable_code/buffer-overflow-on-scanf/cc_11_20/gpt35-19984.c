//FormAI DATASET v1.0 Category: File Synchronizer ; Style: surprised
#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>

int main()
{
    printf("SURPRISE! I'm a C File Synchronizer\n\n");
    printf("Let's sync some files...\n\n");

    char source[100],dest[100];
    printf("Enter source directory path: ");
    scanf("%s",source);
    printf("Enter destination directory path: ");
    scanf("%s",dest);

    DIR *d1=opendir(source);
    DIR *d2=opendir(dest);

    if(d1==NULL || d2==NULL) {
        printf("Unable to open directory\n");
        exit(1);
    }
    printf("Directories opened successfully!\n\n");

    // checking for list of files in source directory
    struct dirent *f1;
    int global_count=0;
    while((f1=readdir(d1))!=NULL) {
        if(strcmp(f1->d_name,".")!=0 && strcmp(f1->d_name,"..")!=0) {
            global_count++;
            int local_count=0;
            char source_path[100],dest_path[100];
            sprintf(source_path,"%s/%s",source,f1->d_name);
            sprintf(dest_path,"%s/%s",dest,f1->d_name);
            struct stat file_stat1,file_stat2;
            if(stat(source_path,&file_stat1)<0) {
                printf("Error in file stat\n");
                exit(1);
            }
            // checking whether the file exists in destination directory or not
            if(stat(dest_path,&file_stat2)>=0) {
                if(file_stat1.st_mtime>file_stat2.st_mtime) {
                    printf("%s is updated\n",f1->d_name);
                    FILE *src,*des;
                    src=fopen(source_path,"r");
                    des=fopen(dest_path,"w");
                    char ch=fgetc(src);
                    while(ch!=EOF) {
                        fputc(ch,des);
                        ch=fgetc(src);
                    }
                    fclose(src);
                    fclose(des);
                    printf("%s is updated in destination directory\n",f1->d_name);
                }
                else if(file_stat2.st_mtime>file_stat1.st_mtime) {
                    printf("%s is updated\n",f1->d_name);
                    FILE *src,*des;
                    src=fopen(dest_path,"r");
                    des=fopen(source_path,"w");
                    char ch=fgetc(src);
                    while(ch!=EOF) {
                        fputc(ch,des);
                        ch=fgetc(src);
                    }
                    fclose(src);
                    fclose(des);
                    printf("%s is updated in source directory\n",f1->d_name);
                }
                else {
                    printf("%s is already in sync\n",f1->d_name);
                }
                local_count++;
            }
            else {
                printf("%s is added in destination directory\n",f1->d_name);
                FILE *src,*des;
                src=fopen(source_path,"r");
                des=fopen(dest_path,"w");
                char ch=fgetc(src);
                while(ch!=EOF) {
                    fputc(ch,des);
                    ch=fgetc(src);
                }
                fclose(src);
                fclose(des);
                local_count++;
            }
            if(local_count==0) {
                printf("%s is not found in destination directory\n",f1->d_name);
                global_count--;
            }
        }
    }
    printf("Synchronization completed!\n");
    printf("Total %d files are synchronized\n", global_count);
    closedir(d1);
    closedir(d2);
    return 0;
}