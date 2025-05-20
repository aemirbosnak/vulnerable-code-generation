//FormAI DATASET v1.0 Category: File Synchronizer ; Style: modular
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<dirent.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<errno.h>

#define BUFFER_SIZE 1024

int copy_file(char* src_file, char* dest_file);
int copy_dir(char* src_dir, char* dest_dir);

int main(int argc, char* argv[]) {
  if(argc != 3) {
    printf("Usage: %s source_directory destination_directory\n", argv[0]);
    exit(1);
  }
  
  char* src_dir = argv[1];
  char* dest_dir = argv[2];
  
  struct stat src_stat, dest_stat;
  if(stat(src_dir, &src_stat) == -1) {
    printf("Unable to obtain stat info of source directory\n");
    exit(1);
  }
  if(stat(dest_dir, &dest_stat) == -1) {
    if(mkdir(dest_dir, src_stat.st_mode) == -1) {
      printf("Unable to create destination directory. Error: %s\n", strerror(errno));
      exit(1);
    }
    else {
      printf("Destination directory created.\n");
      if(stat(dest_dir, &dest_stat) == -1) {
        printf("Unable to obtain stat info of destination directory after creation\n");
        exit(1);
      }
    }
  }
  
  if(!S_ISDIR(src_stat.st_mode)) {
    printf("Source is not a directory.\n");
    exit(1);
  }
  
  if(!S_ISDIR(dest_stat.st_mode)) {
    printf("Destination is not a directory.\n");
    exit(1);
  }
  
  DIR* src_dir_ptr = opendir(src_dir);
  if(src_dir_ptr == NULL) {
    printf("Unable to open source directory. Error: %s\n", strerror(errno));
    exit(1);
  }
  
  struct dirent* src_dirent_ptr;
  while((src_dirent_ptr = readdir(src_dir_ptr)) != NULL) {
    if(src_dirent_ptr->d_name[0] == '.') {
      continue;
    }
    char* src_file = (char*) malloc(BUFFER_SIZE*sizeof(char));
    strncpy(src_file, src_dir, BUFFER_SIZE);
    strncat(src_file, "/", BUFFER_SIZE);
    strncat(src_file, src_dirent_ptr->d_name, BUFFER_SIZE);
    char* dest_file = (char*) malloc(BUFFER_SIZE*sizeof(char));
    strncpy(dest_file, dest_dir, BUFFER_SIZE);
    strncat(dest_file, "/", BUFFER_SIZE);
    strncat(dest_file, src_dirent_ptr->d_name, BUFFER_SIZE);
    if(stat(src_file, &src_stat) == -1) {
      printf("Unable to obtain stat info of source file %s. Error: %s\n", src_file, strerror(errno));
      exit(1);
    }
    if(S_ISDIR(src_stat.st_mode)) {
      if(copy_dir(src_file, dest_file) == -1) {
        printf("Unable to copy directory %s to %s. Error: %s\n", src_file, dest_file, strerror(errno));
        exit(1);
      }
    }
    else if(S_ISREG(src_stat.st_mode)) {
      if(copy_file(src_file, dest_file) == -1) {
        printf("Unable to copy file %s to %s. Error: %s\n", src_file, dest_file, strerror(errno));
        exit(1);
      }
    }
  }
  closedir(src_dir_ptr);
  
  printf("Synchronization complete.\n");
  return 0;
}

int copy_file(char* src_file, char* dest_file) {
  int src_fd = open(src_file, O_RDONLY);
  if(src_fd == -1) {
    printf("Unable to open source file %s. Error: %s\n", src_file, strerror(errno));
    return -1;
  }
  int dest_fd = open(dest_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
  if(dest_fd == -1) {
    printf("Unable to open/create destination file %s. Error: %s\n", dest_file, strerror(errno));
    return -1;
  }
  char buffer[BUFFER_SIZE];
  int bytes_read;
  while((bytes_read = read(src_fd, buffer, BUFFER_SIZE)) > 0) {
    int bytes_written = write(dest_fd, buffer, bytes_read);
    if(bytes_written != bytes_read) {
      printf("Error in writing to destination file %s. Error: %s\n", dest_file, strerror(errno));
      return -1;
    }
  }
  close(src_fd);
  close(dest_fd);
  return 0;
}

int copy_dir(char* src_dir, char* dest_dir) {
  struct stat src_stat, dest_stat;
  if(stat(src_dir, &src_stat) == -1) {
    printf("Unable to obtain stat info of source directory %s\n", src_dir);
    return -1;
  }
  if(stat(dest_dir, &dest_stat) == -1) {
    if(mkdir(dest_dir, src_stat.st_mode) == -1) {
      printf("Unable to create destination directory %s. Error: %s\n", dest_dir, strerror(errno));
      return -1;
    }
    else {
      printf("Destination directory %s created.\n", dest_dir);
      if(stat(dest_dir, &dest_stat) == -1) {
        printf("Unable to obtain stat info of destination directory %s after creation\n", dest_dir);
        return -1;
      }
    }
  }
  
  if(!S_ISDIR(src_stat.st_mode)) {
    printf("Source %s is not a directory.\n", src_dir);
    return -1;
  }
  
  if(!S_ISDIR(dest_stat.st_mode)) {
    printf("Destination %s is not a directory.\n", dest_dir);
    return -1;
  }
  
  DIR* src_dir_ptr = opendir(src_dir);
  if(src_dir_ptr == NULL) {
    printf("Unable to open source directory %s. Error: %s\n", src_dir, strerror(errno));
    return -1;
  }
  
  struct dirent* src_dirent_ptr;
  while((src_dirent_ptr = readdir(src_dir_ptr)) != NULL) {
    if(src_dirent_ptr->d_name[0] == '.') {
      continue;
    }
    char* src_file = (char*) malloc(BUFFER_SIZE*sizeof(char));
    strncpy(src_file, src_dir, BUFFER_SIZE);
    strncat(src_file, "/", BUFFER_SIZE);
    strncat(src_file, src_dirent_ptr->d_name, BUFFER_SIZE);
    char* dest_file = (char*) malloc(BUFFER_SIZE*sizeof(char));
    strncpy(dest_file, dest_dir, BUFFER_SIZE);
    strncat(dest_file, "/", BUFFER_SIZE);
    strncat(dest_file, src_dirent_ptr->d_name, BUFFER_SIZE);
    if(stat(src_file, &src_stat) == -1) {
      printf("Unable to obtain stat info of source file %s. Error: %s\n", src_file, strerror(errno));
      exit(1);
    }
    if(S_ISDIR(src_stat.st_mode)) {
      if(copy_dir(src_file, dest_file) == -1) {
        printf("Unable to copy directory %s to %s. Error: %s\n", src_file, dest_file, strerror(errno));
        exit(1);
      }
    }
    else if(S_ISREG(src_stat.st_mode)) {
      if(copy_file(src_file, dest_file) == -1) {
        printf("Unable to copy file %s to %s. Error: %s\n", src_file, dest_file, strerror(errno));
        exit(1);
      }
    }
  }
  closedir(src_dir_ptr);
  
  return 0;
}