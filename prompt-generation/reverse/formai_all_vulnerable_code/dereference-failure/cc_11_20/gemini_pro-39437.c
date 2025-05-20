//GEMINI-pro DATASET v1.0 Category: File Synchronizer ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>

#define BUFSIZE 1024

struct file_info {
	char *name;
	off_t size;
	time_t mtime;
};

int compare_files(const void *a, const void *b) {
	const struct file_info *fa = (const struct file_info *)a;
	const struct file_info *fb = (const struct file_info *)b;

	return strcmp(fa->name, fb->name);
}

int main(int argc, char *argv[]) {
	if (argc != 3) {
		fprintf(stderr, "Usage: %s <source> <destination>\n", argv[0]);
		return 1;
	}

	char *source = argv[1];
	char *destination = argv[2];

	DIR *source_dir = opendir(source);
	if (source_dir == NULL) {
		perror("opendir(source)");
		return 1;
	}

	DIR *destination_dir = opendir(destination);
	if (destination_dir == NULL) {
		perror("opendir(destination)");
		return 1;
	}

	struct dirent *source_dent;
	struct dirent *destination_dent;

	struct file_info *source_files = NULL;
	struct file_info *destination_files = NULL;

	size_t source_files_size = 0;
	size_t destination_files_size = 0;

	while ((source_dent = readdir(source_dir)) != NULL) {
		if (strcmp(source_dent->d_name, ".") == 0 || strcmp(source_dent->d_name, "..") == 0) {
			continue;
		}

		struct stat source_stat;
		if (stat(source_dent->d_name, &source_stat) == -1) {
			perror("stat(source_dent->d_name)");
			continue;
		}

		struct file_info *file_info = malloc(sizeof(struct file_info));
		if (file_info == NULL) {
			perror("malloc(file_info)");
			continue;
		}

		file_info->name = strdup(source_dent->d_name);
		if (file_info->name == NULL) {
			perror("strdup(source_dent->d_name)");
			free(file_info);
			continue;
		}

		file_info->size = source_stat.st_size;
		file_info->mtime = source_stat.st_mtime;

		if (source_files_size == 0) {
			source_files = file_info;
		} else {
			source_files = realloc(source_files, (source_files_size + 1) * sizeof(struct file_info));
			if (source_files == NULL) {
				perror("realloc(source_files)");
				free(file_info->name);
				free(file_info);
				continue;
			}

			source_files[source_files_size] = *file_info;
		}

		source_files_size++;
	}

	qsort(source_files, source_files_size, sizeof(struct file_info), compare_files);

	while ((destination_dent = readdir(destination_dir)) != NULL) {
		if (strcmp(destination_dent->d_name, ".") == 0 || strcmp(destination_dent->d_name, "..") == 0) {
			continue;
		}

		struct stat destination_stat;
		if (stat(destination_dent->d_name, &destination_stat) == -1) {
			perror("stat(destination_dent->d_name)");
			continue;
		}

		struct file_info *file_info = malloc(sizeof(struct file_info));
		if (file_info == NULL) {
			perror("malloc(file_info)");
			continue;
		}

		file_info->name = strdup(destination_dent->d_name);
		if (file_info->name == NULL) {
			perror("strdup(destination_dent->d_name)");
			free(file_info);
			continue;
		}

		file_info->size = destination_stat.st_size;
		file_info->mtime = destination_stat.st_mtime;

		if (destination_files_size == 0) {
			destination_files = file_info;
		} else {
			destination_files = realloc(destination_files, (destination_files_size + 1) * sizeof(struct file_info));
			if (destination_files == NULL) {
				perror("realloc(destination_files)");
				free(file_info->name);
				free(file_info);
				continue;
			}

			destination_files[destination_files_size] = *file_info;
		}

		destination_files_size++;
	}

	qsort(destination_files, destination_files_size, sizeof(struct file_info), compare_files);

	size_t i;
	for (i = 0; i < source_files_size; i++) {
		struct file_info *source_file = &source_files[i];
		struct file_info *destination_file = NULL;

		size_t j;
		for (j = 0; j < destination_files_size; j++) {
			if (strcmp(source_file->name, destination_files[j].name) == 0) {
				destination_file = &destination_files[j];
				break;
			}
		}

		if (destination_file == NULL) {
			printf("File not found in destination: %s\n", source_file->name);
			continue;
		}

		if (source_file->size != destination_file->size || source_file->mtime != destination_file->mtime) {
			printf("File is different in destination: %s\n", source_file->name);
			continue;
		}

		printf("File is the same: %s\n", source_file->name);
	}

	closedir(source_dir);
	closedir(destination_dir);

	for (i = 0; i < source_files_size; i++) {
		free(source_files[i].name);
	}

	free(source_files);

	for (i = 0; i < destination_files_size; i++) {
		free(destination_files[i].name);
	}

	free(destination_files);

	return 0;
}