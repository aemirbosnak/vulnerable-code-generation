//Code Llama-13B DATASET v1.0 Category: File system simulation ; Style: complex
#include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include <stdbool.h>

  // Structures
  typedef struct _file_system {
    char *name;
    char *path;
    char *type;
    char *size;
    char *data;
    bool is_dir;
    struct _file_system *next;
  } file_system_t;

  typedef struct _file_system_dir {
    char *name;
    char *path;
    char *type;
    char *size;
    char *data;
    bool is_dir;
    struct _file_system_dir *next;
  } file_system_dir_t;

  // Functions
  file_system_t* create_file_system(char *name, char *path, char *type, char *size, char *data, bool is_dir) {
    file_system_t *file = malloc(sizeof(file_system_t));
    file->name = strdup(name);
    file->path = strdup(path);
    file->type = strdup(type);
    file->size = strdup(size);
    file->data = strdup(data);
    file->is_dir = is_dir;
    file->next = NULL;
    return file;
  }

  file_system_dir_t* create_file_system_dir(char *name, char *path, char *type, char *size, char *data, bool is_dir) {
    file_system_dir_t *dir = malloc(sizeof(file_system_dir_t));
    dir->name = strdup(name);
    dir->path = strdup(path);
    dir->type = strdup(type);
    dir->size = strdup(size);
    dir->data = strdup(data);
    dir->is_dir = is_dir;
    dir->next = NULL;
    return dir;
  }

  void add_file_system_node(file_system_t *fs, file_system_t *node) {
    if (fs->next == NULL) {
      fs->next = node;
    } else {
      add_file_system_node(fs->next, node);
    }
  }

  void add_file_system_dir_node(file_system_dir_t *fs, file_system_dir_t *node) {
    if (fs->next == NULL) {
      fs->next = node;
    } else {
      add_file_system_dir_node(fs->next, node);
    }
  }

  file_system_t* find_file_system_node(file_system_t *fs, char *name) {
    if (fs == NULL) {
      return NULL;
    }
    if (strcmp(fs->name, name) == 0) {
      return fs;
    }
    return find_file_system_node(fs->next, name);
  }

  file_system_dir_t* find_file_system_dir_node(file_system_dir_t *fs, char *name) {
    if (fs == NULL) {
      return NULL;
    }
    if (strcmp(fs->name, name) == 0) {
      return fs;
    }
    return find_file_system_dir_node(fs->next, name);
  }

  void delete_file_system_node(file_system_t *fs) {
    if (fs == NULL) {
      return;
    }
    free(fs->name);
    free(fs->path);
    free(fs->type);
    free(fs->size);
    free(fs->data);
    free(fs);
  }

  void delete_file_system_dir_node(file_system_dir_t *fs) {
    if (fs == NULL) {
      return;
    }
    free(fs->name);
    free(fs->path);
    free(fs->type);
    free(fs->size);
    free(fs->data);
    free(fs);
  }

  void delete_file_system(file_system_t *fs) {
    file_system_t *node = fs;
    while (node != NULL) {
      file_system_t *tmp = node->next;
      delete_file_system_node(node);
      node = tmp;
    }
  }

  void delete_file_system_dir(file_system_dir_t *fs) {
    file_system_dir_t *node = fs;
    while (node != NULL) {
      file_system_dir_t *tmp = node->next;
      delete_file_system_dir_node(node);
      node = tmp;
    }
  }

  // Main
  int main(int argc, char *argv[]) {
    file_system_t *fs = create_file_system("root", "/", "root", "1000", "Hello World", false);
    file_system_dir_t *fs_dir = create_file_system_dir("home", "/home", "home", "1000", "Hello World", true);
    add_file_system_node(fs, fs_dir);
    file_system_t *node = find_file_system_node(fs, "home");
    if (node != NULL) {
      printf("Found node: %s\n", node->name);
    }
    delete_file_system(fs);
    delete_file_system_dir(fs_dir);
    return 0;
  }